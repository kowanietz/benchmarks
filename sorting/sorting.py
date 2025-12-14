import ctypes
import os
import sys

if sys.platform == "darwin":
    LIB_NAME = "libsorting.dylib"
elif sys.platform == "win32":
    LIB_NAME = "sorting.dll"
else:
    LIB_NAME = "libsorting.so"

_LIB_PATH = os.path.join(os.path.dirname(__file__), "..", "build", "sorting", LIB_NAME)

lib = ctypes.CDLL(_LIB_PATH)

lib.bubble_sort_naive.restype = None
lib.bubble_sort_naive.argtypes = [
    ctypes.POINTER(ctypes.c_int32),
    ctypes.c_uint32,
]


def bubble_sort_naive(arr: list[int]) -> list[int]:
    n = len(arr)
    arr_copy = arr.copy()
    c_arr = (ctypes.c_int32 * n)(*arr_copy)
    lib.bubble_sort_naive(c_arr, n)
    return list(c_arr)
