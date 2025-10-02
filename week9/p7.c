#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void getPairs(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == 0) {
            printf("[%d, %d]\n", arr[left], arr[right]);
            int left_val = arr[left], right_val = arr[right];
            while (left < right && arr[left] == left_val) left++;
            while (left < right && arr[right] == right_val) right--;
        } 
        else if (sum < 0) left++;
        else right--;
    }
}

int main() {
    int arr1[] = {-1, 0, 1, 2, -1, -4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    getPairs(arr1, n1);

    int arr2[] = {6, 1, 8, 0, 4, -9, -1, -10, -6, -5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    getPairs(arr2, n2);

    return 0;
}
