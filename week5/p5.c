int evaluate(char* arr[], int size) {
    int* stack = (int*)malloc(size * sizeof(int));
    int top = -1;

    for (int i = 0; i < size; i++) {
        char* token = arr[i];
        if (strcmp(token, "+") && strcmp(token, "-") && strcmp(token, "*") && strcmp(token, "/") && strcmp(token, "^")) {
            stack[++top] = atoi(token);
        } else {
            int b = stack[top--];
            int a = stack[top--];
            if (strcmp(token, "+") == 0) {
                stack[++top] = a + b;
            } else if (strcmp(token, "-") == 0) {
                stack[++top] = a - b;
            } else if (strcmp(token, "*") == 0) {
                stack[++top] = a * b;
            } else if (strcmp(token, "/") == 0) {
                int res = a / b;
                if ((a % b != 0) && ((a < 0) != (b < 0))) res--;  
                stack[++top] = res;
            } else if (strcmp(token, "^") == 0) {
                stack[++top] = (int)pow(a, b);
            }
        }
    }

    int result = stack[top];
    free(stack);
    return result;
}