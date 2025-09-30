int* calculateSpan(int* arr, int n) {
    int* span = (int*)malloc(n * sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[stack[top]] <= arr[i]) {
            top--;
        }
        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }

    free(stack);
    return span;
}