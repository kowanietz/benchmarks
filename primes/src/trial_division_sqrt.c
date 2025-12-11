#include <stdint.h>
#include <stdbool.h>
#include <math.h>

uint32_t trial_division_sqrt(const uint32_t n) {
    if (n == 0) return 2;

    uint32_t count = 0;
    uint32_t candidate = 2;

    while (count <= n) {
        bool is_prime = true;

        // checking the divisibility only up to sqrt
        // seems marginal but actually reduces hte number of iteraitons significantly
        for (uint32_t divisor = 2; divisor < floor(sqrt(candidate)) + 1; divisor++) {
            if (candidate % divisor == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            count++;
        }
        candidate++;
    }

    return candidate - 1;
}
