#include <stdio.h>

#define MAX 1000

struct Solution {
    void (*linearProbing)(int arr[], int n, int m, int hashtable[]);
};

void linearProbingImpl(int arr[], int n, int m, int hashtable[]) {
    for (int i = 0; i < m; i++) hashtable[i] = -1;
    for (int i = 0; i < n; i++) {
        int val = arr[i];
        int idx = val % m;
        int start = idx;
        while (1) {
            if (hashtable[idx] == -1) {
                hashtable[idx] = val;
                break;
            } else if (hashtable[idx] == val) {
                break;
            } else {
                idx = (idx + 1) % m;
                if (idx == start) break;
            }
        }
    }
}

int main() {
    struct Solution sol;
    sol.linearProbing = linearProbingImpl;

    int arr[] = {4, 14, 24, 44};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 10;
    int hashtable[MAX];

    sol.linearProbing(arr, n, m, hashtable);

    for (int i = 0; i < m; i++) {
        printf("%d ", hashtable[i]);
    }
    return 0;
}
