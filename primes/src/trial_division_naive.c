#include <stdint.h>
#include <stdbool.h>

uint32_t trial_division_naive(const uint32_t n) {
    if (n == 0) return 2;

    uint32_t count = 0;
    uint32_t candidate = 2;

    while (count <= n) {
        bool is_prime = true;

        for (uint32_t divisor = 2; divisor < candidate; divisor++) {
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
