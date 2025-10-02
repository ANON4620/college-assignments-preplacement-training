#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPS 100000
#define MAX_LEN 100000

typedef struct {
    char **states;
    int top;
} Stack;

char* string_copy(const char *src) {
    char *dest = malloc(strlen(src) + 1);
    if (dest) strcpy(dest, src);
    return dest;
}

void push(Stack *stack, const char *state) {
    stack->states[++stack->top] = string_copy(state);
}

char* pop(Stack *stack) {
    if (stack->top == -1) return NULL;
    return stack->states[stack->top--];
}

int main() {
    int q;
    scanf("%d", &q);

    char *text = string_copy(""); // start with empty string
    Stack history;
    history.states = malloc(sizeof(char*) * MAX_OPS);
    history.top = -1;

    for (int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) { // append
            char w[MAX_LEN];
            scanf("%s", w);

            push(&history, text);

            size_t newLen = strlen(text) + strlen(w) + 1;
            char *newText = malloc(newLen);
            strcpy(newText, text);
            strcat(newText, w);

            free(text);
            text = newText;

        } else if (op == 2) { // delete
            int k;
            scanf("%d", &k);

            push(&history, text);

            size_t len = strlen(text);
            if (k > len) k = len;
            text[len - k] = '\0';

            char *newText = string_copy(text);
            free(text);
            text = newText;

        } else if (op == 3) { // print
            int k;
            scanf("%d", &k);
            if (k > 0 && k <= strlen(text)) {
                printf("%c\n", text[k - 1]);
            }

        } else if (op == 4) { // undo
            char *prev = pop(&history);
            if (prev) {
                free(text);
                text = prev;
            }
        }
    }

    free(text);
    while (history.top >= 0) free(history.states[history.top--]);
    free(history.states);

    return 0;
}
