#include <stdio.h>

int main() {
    int arr[] = {2, 3, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int freq[n];
    for (int i = 0; i < n; i++)
        freq[i] = 0;

    for (int i = 0; i < n; i++)
        freq[arr[i] - 1]++;

    for (int i = 0; i < n; i++)
        printf("%d ", freq[i]);

    return 0;
}
