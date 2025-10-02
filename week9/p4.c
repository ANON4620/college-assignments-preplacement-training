void findDuplicates(int arr[], int n) {
    int *res = (int*)malloc(n * sizeof(int));
    int res_count = 0;

    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0) {
            res[res_count++] = index + 1;
        } else {
            arr[index] = -arr[index];
        }
    }

    if (res_count == 0) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i < res_count; i++) {
            printf("%d", res[i]);
            if (i != res_count - 1) printf(", ");
        }
        printf("]\n");
    }

    free(res);
}