#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxLength(char* s) {
    int n = strlen(s);
    int* stack = malloc(sizeof(int) * (n + 1));
    int top = -1;
    int max_len = 0;

    stack[++top] = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                int len = i - stack[top];
                if (len > max_len)
                    max_len = len;
            }
        }
    }

    free(stack);
    return max_len;
}

int main() {
    printf("%d\n", maxLength("((()"));
    printf("%d\n", maxLength(")()())"));
    printf("%d\n", maxLength("())()"));
    return 0;
}
