#include <stdio.h>

int diagonalSum(int N, int M[50][50]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += M[i][i];
    }
    return sum;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int M[50][50];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &M[i][j]);
            }
        }
        printf("%d\n", diagonalSum(N, M));
    }
    return 0;
}
