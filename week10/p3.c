#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int* heights, int m) {
    int* stack = malloc(sizeof(int) * m);
    int top = -1;
    int max_area = 0;
    int i = 0;

    while (i < m) {
        if (top == -1 || heights[stack[top]] <= heights[i]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int w = top == -1 ? i : i - stack[top] - 1;
            if (h * w > max_area) max_area = h * w;
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int w = top == -1 ? i : i - stack[top] - 1;
        if (h * w > max_area) max_area = h * w;
    }

    free(stack);
    return max_area;
}

int maxArea(int** mat, int n, int m) {
    int* heights = calloc(m, sizeof(int));
    int max_area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0)
                heights[j] = 0;
            else
                heights[j] += 1;
        }
        int area = largestRectangleArea(heights, m);
        if (area > max_area) max_area = area;
    }

    free(heights);
    return max_area;
}

int main() {
    int n = 4, m = 4;
    int mat_data[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int** mat = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            mat[i][j] = mat_data[i][j];
        }
    }

    printf("%d\n", maxArea(mat, n, m)); // Output: 8

    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
    return 0;
}
