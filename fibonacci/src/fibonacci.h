#ifndef FIB_H
#define FIB_H
#include <gmp.h>

void fib_naive(mpz_t result, int n);

void fib_linear(mpz_t result, int n);

void fib_matmul_naive(mpz_t result, int n);

void fib_matmul_fastexp(mpz_t result, int n);

void fib_matmul_3var(mpz_t result, int n);

void fib_matmul_2var(mpz_t result, int n);

void fib_fast_doubling(mpz_t result, int n);

void fib_gmp(mpz_t result, int n);


// wrappers implemented in the fibonacci.c  macro
const char *fib_naive_str(int n);

const char *fib_linear_str(int n);

const char *fib_matmul_naive_str(int n);

const char *fib_matmul_fastexp_str(int n);

const char *fib_matmul_3var_str(int n);

const char *fib_matmul_2var_str(int n);

const char *fib_fast_doubling_str(int n);

const char *fib_gmp_str(int n);


#endif
