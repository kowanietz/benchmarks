#include <gmp.h>
#include "fibonacci.h"

static void fib_fast_doubling_internal(mpz_t Fn, mpz_t Fnp1, unsigned long n) {
    if (n == 0) {
        mpz_set_ui(Fn, 0);
        mpz_set_ui(Fnp1, 1);
        return;
    }

    mpz_t a, b, t1, t2;
    mpz_inits(a, b, t1, t2, NULL);

    fib_fast_doubling_internal(a, b, n >> 1);

    mpz_mul_ui(t1, b, 2);
    mpz_sub(t1, t1, a);
    mpz_mul(t1, t1, a);

    mpz_mul(t2, a, a);
    mpz_addmul(t2, b, b);

    if ((n & 1) == 0) {
        mpz_set(Fn, t1);
        mpz_set(Fnp1, t2);
    } else {
        mpz_set(Fn, t2);
        mpz_add(Fnp1, t1, t2);
    }

    mpz_clears(a, b, t1, t2, NULL);
}

void fib_fast_doubling(mpz_t result, int n) {
    mpz_t Fn, Fnp1;
    mpz_inits(Fn, Fnp1, NULL);

    fib_fast_doubling_internal(Fn, Fnp1, n);

    mpz_set(result, Fn);

    mpz_clears(Fn, Fnp1, NULL);
}
