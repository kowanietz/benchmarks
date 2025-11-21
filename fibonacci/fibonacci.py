import ctypes
import os
import sys

if sys.platform == "darwin":
    LIB_NAME = "libfib.dylib"
elif sys.platform == "win32":
    LIB_NAME = "fib.dll"
else:
    LIB_NAME = "libfib.so"

_LIB_PATH = os.path.join(
    os.path.dirname(__file__), "..", "build", "fibonacci", LIB_NAME
)

lib = ctypes.CDLL(_LIB_PATH)

# return raw pointer as void* so ctypes doesn't attempt to manage/free it
lib.fib_naive_str.restype = ctypes.c_void_p
lib.fib_linear_str.restype = ctypes.c_void_p
lib.fib_matmul_naive_str.restype = ctypes.c_void_p
lib.fib_matmul_fastexp_str.restype = ctypes.c_void_p
lib.fib_matmul_3var_str.restype = ctypes.c_void_p
lib.fib_matmul_2var_str.restype = ctypes.c_void_p
lib.fib_fast_doubling_str.restype = ctypes.c_void_p
lib.fib_gmp_str.restype = ctypes.c_void_p

# bind free_str
lib.free_str.argtypes = (ctypes.c_void_p,)
lib.free_str.restype = None


def _call(func, n: int) -> str:
    raw_ptr = func(n)
    if not raw_ptr:
        raise RuntimeError("C function returned NULL")

    # convert pointer to Python string
    py_str = ctypes.cast(raw_ptr, ctypes.c_char_p).value.decode("utf-8")

    # free vie free_str so the same allocator deallocates it
    lib.free_str(raw_ptr)

    return py_str


def fib_naive(n: int) -> str:
    return _call(lib.fib_naive_str, n)


def fib_linear(n: int) -> str:
    return _call(lib.fib_linear_str, n)


def fib_matmul_naive(n: int) -> str:
    return _call(lib.fib_matmul_naive_str, n)


def fib_matmul_fastexp(n: int) -> str:
    return _call(lib.fib_matmul_fastexp_str, n)


def fib_matmul_3var(n: int) -> str:
    return _call(lib.fib_matmul_3var_str, n)


def fib_matmul_2var(n: int) -> str:
    return _call(lib.fib_matmul_2var_str, n)


def fib_fast_doubling(n: int) -> str:
    return _call(lib.fib_fast_doubling_str, n)


def fib_gmp(n: int) -> str:
    return _call(lib.fib_gmp_str, n)
