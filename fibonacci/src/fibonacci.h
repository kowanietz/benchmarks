#ifndef FIB_H
#define FIB_H
#include <gmp.h>

void fib_naive(mpz_t result, int n);

void fib_linear(mpz_t result, int n);


// wrappers implemented in the fobinacci.c  macro
const char *fib_naive_str(int n);

const char *fib_linear_str(int n);


#endif
