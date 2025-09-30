int* nextLargerElement(int* arr, int n) {
    int* result = (int*)malloc(n * sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) result[i] = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[i] > arr[stack[top]]) {
            result[stack[top--]] = arr[i];
        }
        stack[++top] = i;
    }

    free(stack);
    return result;
}