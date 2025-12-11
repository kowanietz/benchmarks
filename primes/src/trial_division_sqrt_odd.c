#include <stdint.h>
#include <stdbool.h>

uint32_t trial_division_sqrt_odd(const uint32_t n) {
    if (n == 0) return 2;

    uint32_t count = 1;
    uint32_t candidate = 3;

    while (count <= n) {
        bool is_prime = true;

        // ocne again only checking up to sqrt
        // this time only checking odd divisors
        // -> another huge speedup
        for (uint32_t divisor = 3; divisor * divisor <= candidate; divisor += 2) {
            if (candidate % divisor == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            count++;
        }
        candidate += 2; // Skip even numbers
    }

    return candidate - 2;
}
