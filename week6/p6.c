#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node *front, *rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (!q->rear) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if (!q->front) return -1;
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    q->size--;
    return val;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void reverseFirstK(Queue* q, int k) {
    if (k > q->size || k <= 0) return;

    int* stack = (int*)malloc(k * sizeof(int));
    int top = -1;

    for (int i = 0; i < k; i++) {
        stack[++top] = dequeue(q);
    }
    while (top >= 0) {
        enqueue(q, stack[top--]);
    }
    int t = q->size - k;
    while (t--) {
        enqueue(q, dequeue(q));
    }
    free(stack);
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    reverseFirstK(q, 3);

    printQueue(q); // Output: 3 2 1 4 5

    return 0;
}
