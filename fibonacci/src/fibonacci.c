#include <gmp.h>
#include "fibonacci.h"
#include "bigint_utils.h"

// wraps fib functions with bigint functionalitiesd
#define MAKE_FIB_STR_WRAPPER(funcname)          \
    const char* funcname##_str(int n) {         \
        mpz_t result;                           \
        mpz_init(result);                       \
        funcname(result, n);                    \
        char* s = mpz_to_str(result);           \
        mpz_clear(result);                      \
        return s;                               \
}

MAKE_FIB_STR_WRAPPER(fib_naive)
MAKE_FIB_STR_WRAPPER(fib_linear)
