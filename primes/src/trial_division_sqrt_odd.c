#include <stdint.h>
#include <stdbool.h>
#include <math.h>

uint32_t trial_division_sqrt_odd(const uint32_t n) {
    if (n == 0) return 2;

    uint32_t count = 0;
    uint32_t candidate = 2;

    while (count < n) {
        bool is_prime = true;

        // ocne again only checking up to sqrt
        // this time only checking odd divisors
        // -> another huge speedup
        for (uint32_t divisor = 2; divisor < floor(sqrt(candidate)) + 1; divisor += 2) {
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
