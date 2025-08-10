#include <stdio.h>

int countZeros(int N, int A[][1000]) {
    int count = 0;
    int i = 0, j = N - 1; // start from top-right
    while (i < N && j >= 0) {
        if (A[i][j] == 0) {
            count += (j + 1); // all elements in this row till j are zero
            i++; // move to next row
        } else {
            j--; // move left
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);
    int A[1000][1000];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);
    printf("%d\n", countZeros(N, A));
    return 0;
}
