#include <stdlib.h>
#include <string.h>
#include "bigint_utils.h"

char *mpz_to_str(const mpz_t value) {
    // NULL -> GMP allocates the string via malloc
    // 10 -> base 10 (decmial)
    char *raw = mpz_get_str(NULL, 10, value);

    // string allcoated via malloc -> has to be freed by the caller (C allocator)
    return raw;
}

void free_str(char *s) {
    // use the C allocator's free to release the memory allocated by GMP
    free(s);
}
