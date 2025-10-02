#define MAX 200005

int twoSum(int arr[], int n, int target) {
    int hash[MAX] = {0};
    int offset = 100000; // to handle negative numbers

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (complement + offset >= 0 && complement + offset < MAX && hash[complement + offset]) {
            return 1; // true
        }
        hash[arr[i] + offset] = 1;
    }
    return 0; // false
}