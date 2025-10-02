int longestConsecutive(int arr[], int n) {
    int present[MAX] = {0};
    int max_val = 0;

    for (int i = 0; i < n; i++) {
        present[arr[i]] = 1;
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    int max_len = 0;
    for (int i = 0; i <= max_val; i++) {
        if (present[i] && (i == 0 || !present[i - 1])) {
            int length = 1;
            while (present[i + length]) {
                length++;
            }
            if (length > max_len)
                max_len = length;
        }
    }
    return max_len;
}