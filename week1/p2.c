#include <stdio.h>

int main() {
    int arr[] = {1, 8, 7, 56, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("%d\n", max);
    return 0;
}
