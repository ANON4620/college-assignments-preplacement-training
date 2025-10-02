#include <stdio.h>
#include <stdlib.h>

int getMaxArea(int* arr, int n) {
    int* stack = malloc(sizeof(int) * n);
    int top = -1;
    int max_area = 0;
    int i = 0;

    while (i < n) {
        if (top == -1 || arr[stack[top]] <= arr[i]) {
            stack[++top] = i++;
        } else {
            int height = arr[stack[top--]];
            int width = top == -1 ? i : i - stack[top] - 1;
            if (height * width > max_area)
                max_area = height * width;
        }
    }

    while (top != -1) {
        int height = arr[stack[top--]];
        int width = top == -1 ? i : i - stack[top] - 1;
        if (height * width > max_area)
            max_area = height * width;
    }

    free(stack);
    return max_area;
}

int main() {
    int arr1[] = {60, 20, 50, 40, 10, 50, 60};
    int arr2[] = {3, 5, 1, 7, 5, 9};
    int arr3[] = {3};

    printf("%d\n", getMaxArea(arr1, 7)); // 100
    printf("%d\n", getMaxArea(arr2, 6)); // 15
    printf("%d\n", getMaxArea(arr3, 1)); // 3

    return 0;
}
