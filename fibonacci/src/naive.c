#include <gmp.h>
#include "fibonacci.h"

static void fib_naive_internal(mpz_t result, const int n) {
    if (n < 2) {
        mpz_set_ui(result, n);
        return;
    }

    mpz_t a, b;
    mpz_init(a);
    mpz_init(b);

    fib_naive_internal(a, n - 1);
    fib_naive_internal(b, n - 2);

    mpz_add(result, a, b);

    mpz_clear(a);
    mpz_clear(b);
}

void fib_naive(mpz_t result, const int n) {
    fib_naive_internal(result, n);
}
