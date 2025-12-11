import ctypes
import os
import sys

if sys.platform == "darwin":
    LIB_NAME = "libprimes.dylib"
elif sys.platform == "win32":
    LIB_NAME = "primes.dll"
else:
    LIB_NAME = "libprimes.so"

_LIB_PATH = os.path.join(os.path.dirname(__file__), "..", "build", "primes", LIB_NAME)

lib = ctypes.CDLL(_LIB_PATH)

lib.trial_division_naive.restype = ctypes.c_uint32
lib.trial_division_naive.argtypes = [
    ctypes.c_uint32,
]

lib.trial_division_sqrt.restype = ctypes.c_uint32
lib.trial_division_sqrt.argtypes = [
    ctypes.c_uint32,
]

lib.trial_division_sqrt_odd.restype = ctypes.c_uint32
lib.trial_division_sqrt_odd.argtypes = [
    ctypes.c_uint32,
]


def trial_division_naive(n: int) -> int:
    prime = lib.trial_division_naive(n)

    return prime


def trial_division_sqrt(n: int) -> int:
    prime = lib.trial_division_sqrt(n)

    return prime


def trial_division_sqrt_odd(n: int) -> int:
    prime = lib.trial_division_sqrt_odd(n)

    return prime
