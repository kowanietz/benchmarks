import ctypes
import os
import sys
import numpy as np
import numpy.ctypeslib as npct

if sys.platform == "darwin":
    LIB_NAME = "libmatmul.dylib"
elif sys.platform == "win32":
    LIB_NAME = "matmul.dll"
else:
    LIB_NAME = "libmatmul.so"

_LIB_PATH = os.path.join(
    os.path.dirname(__file__), "..", "build", "matmul", LIB_NAME
)

lib = ctypes.CDLL(_LIB_PATH)

array_2d_double = npct.ndpointer(dtype=np.float64, ndim=2, flags="C_CONTIGUOUS")

lib.naive.restype = None
lib.naive.argtypes = [
    array_2d_double,
    array_2d_double,
    array_2d_double,
    ctypes.c_int,
    ctypes.c_int,
    ctypes.c_int,
]


def naive(a: np.ndarray, b: np.ndarray) -> np.ndarray:
    if a.ndim != 2 or b.ndim != 2:
        raise ValueError("a and b must be 2D arrays")

    m, k1 = a.shape
    k2, n = b.shape

    if k1 != k2:
        raise ValueError(
            f"Incompatible shapes for matmul: {a.shape} and {b.shape}"
        )

    a_c = np.ascontiguousarray(a, dtype=np.float64)
    b_c = np.ascontiguousarray(b, dtype=np.float64)

    c = np.empty((m, n), dtype=np.float64)

    lib.naive(a_c, b_c, c, m, k1, n)

    return c
