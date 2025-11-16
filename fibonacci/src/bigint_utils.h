#ifndef BIGINT_UTILS_H
#define BIGINT_UTILS_H

#include <gmp.h>

char *mpz_to_str(const mpz_t value);

// Free a string allocated by mpz_get_str. Call this from Python (ctypes)
// so the same C allocator that allocated the memory performs the free.
void free_str(char *s);

#endif
