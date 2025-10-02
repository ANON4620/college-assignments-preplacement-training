#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

void countDistinct(int arr[], int n, int k) {
    int freq[MAX + 1] = {0};
    int distinct = 0;

    // first window
    for (int i = 0; i < k; i++) {
        if (freq[arr[i]] == 0)
            distinct++;
        freq[arr[i]]++;
    }
    printf("%d ", distinct);

    // slide the window
    for (int i = k; i < n; i++) {
        int left = arr[i - k];
        freq[left]--;
        if (freq[left] == 0)
            distinct--;

        int right = arr[i];
        if (freq[right] == 0)
            distinct++;
        freq[right]++;

        printf("%d ", distinct);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 1, 3, 4, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 4;
    countDistinct(arr1, n1, k1);   // Output: 3 4 4 3

    int arr2[] = {4, 1, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 2;
    countDistinct(arr2, n2, k2);   // Output: 2 1

    int arr3[] = {1, 1, 1, 1, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int k3 = 3;
    countDistinct(arr3, n3, k3);   // Output: 1 1 1

    return 0;
}
