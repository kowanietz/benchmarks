
void naive(const double *A, const double *B, double *res,
           const int m, const int k, const int n) {

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
