#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    return op == '^';
}

char* infixToPostfix(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1, k = 0;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (isalnum(ch)) {
            result[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                result[k++] = stack[top--];
            }
            top--;
        } else {
            while (top != -1 && ((precedence(stack[top]) > precedence(ch)) ||
                   (precedence(stack[top]) == precedence(ch) && !isRightAssociative(ch)))) {
                if (stack[top] == '(') break;
                result[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        result[k++] = stack[top--];
    }

    result[k] = '\0';
    free(stack);
    return result;
}
