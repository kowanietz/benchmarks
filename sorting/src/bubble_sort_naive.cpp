#include <span>

void bubble_sort(std::span<int32_t> arr) {
    const size_t n = arr.size();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

extern "C" {
void bubble_sort_naive(int32_t *arr, const uint32_t n) {
    bubble_sort(std::span<int32_t>(arr, n));
}
}
