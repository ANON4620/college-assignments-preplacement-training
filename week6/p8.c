#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100005

typedef struct {
    char data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, char ch) {
    q->data[q->rear++] = ch;
}

char dequeue(Queue* q) {
    return q->data[q->front++];
}

char front(Queue* q) {
    return q->data[q->front];
}

char* firstNonRepeating(char* s) {
    static char result[MAX];
    int freq[26] = {0};
    Queue q;
    initQueue(&q);

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        freq[ch - 'a']++;
        enqueue(&q, ch);

        while (!isEmpty(&q) && freq[front(&q) - 'a'] > 1) {
            dequeue(&q);
        }

        result[i] = isEmpty(&q) ? '#' : front(&q);
    }
    result[n] = '\0';
    return result;
}

int main() {
    char s[MAX];
    scanf("%s", s);
    printf("%s\n", firstNonRepeating(s));
    return 0;
}
