#include <stddef.h>

void naive(const double *A, const double *B, double *res,
            const int m, const int k, const int n) {
    // A: m x k
    // B: k x n
    // C: m x n
    // Row-major layout: A[i, t] = A[i*k + t], B[t, j] = B[t*n + j], C[i, j] = C[i*n + j]

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int t = 0; t < k; t++) {
                sum += A[i * k + t] * B[t * n + j];
            }
            res[i * n + j] = sum;
        }
    }
}
