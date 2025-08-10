#include <stdio.h>

int main() {
    int m = 3, n = 3;
    int mat[3][3] = {
        {1, 0, 3},
        {0, 0, 4},
        {6, 0, 0}
    };

    int zero_count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                zero_count++;
            }
        }
    }

    if (zero_count > (m * n) / 2)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
