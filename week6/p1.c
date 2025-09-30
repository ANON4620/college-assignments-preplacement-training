#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;
} myQueue;

myQueue* createQueue(int n) {
    myQueue* q = (myQueue*)malloc(sizeof(myQueue));
    q->capacity = n;
    q->arr = (int*)malloc(n * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

bool isEmpty(myQueue* q) {
    return q->size == 0;
}

bool isFull(myQueue* q) {
    return q->size == q->capacity;
}

void enqueue(myQueue* q, int x) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % q->capacity;
        q->arr[q->rear] = x;
        q->size++;
    }
}

void dequeue(myQueue* q) {
    if (!isEmpty(q)) {
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }
}

int getFront(myQueue* q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->front];
}

int getRear(myQueue* q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->rear];
}
