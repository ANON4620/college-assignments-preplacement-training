#include <stdio.h>

void multiplyPolynomials(int A[], int n, int B[], int m, int res[]) {
    for (int i = 0; i < n + m - 1; i++)
        res[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i + j] += A[i] * B[j];
        }
    }
}

int main() {
    int A[] = {5, 0, 10, 6};
    int B[] = {1, 2, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);
    int res[n + m - 1];

    multiplyPolynomials(A, n, B, m, res);

    for (int i = 0; i < n + m - 1; i++)
        printf("%d ", res[i]);
    printf("\n");

    int A2[] = {1, 9, 3, 4, 7};
    int B2[] = {4, 0, 2, 5};
    n = sizeof(A2) / sizeof(A2[0]);
    m = sizeof(B2) / sizeof(B2[0]);
    int res2[n + m - 1];

    multiplyPolynomials(A2, n, B2, m, res2);

    for (int i = 0; i < n + m - 1; i++)
        printf("%d ", res2[i]);
    printf("\n");

    return 0;
}
