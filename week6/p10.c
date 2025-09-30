#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *s, int val) {
    s->arr[++(s->top)] = val;
}

int pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

typedef struct Queue {
    Stack s1;
    Stack s2;
} Queue;

void enqueue(Queue *q, int val) {
    push(&q->s1, val);
}

void dequeue(Queue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    if (!isEmpty(&q->s2))
        pop(&q->s2);
}

int front(Queue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return peek(&q->s2);
}

int main() {
    int q, type, val;
    scanf("%d", &q);

    Queue queue;
    queue.s1.top = queue.s2.top = -1;

    for (int i = 0; i < q; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &val);
            enqueue(&queue, val);
        } else if (type == 2) {
            dequeue(&queue);
        } else if (type == 3) {
            printf("%d\n", front(&queue));
        }
    }

    return 0;
}
