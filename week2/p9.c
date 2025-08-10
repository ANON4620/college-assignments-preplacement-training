#include <stdio.h>

int isIdentityMatrix(int mat[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && mat[i][j] != 1) // diagonal element should be 1
                return 0;
            else if (i != j && mat[i][j] != 0) // non-diagonal should be 0
                return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int mat[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    if (isIdentityMatrix(mat, n))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
