#include <stdio.h>
#include <stdlib.h>

void rearrangeQueue(int q[], int n) {
    if (n % 2 != 0) return;

    int half = n / 2;
    int stack[half];
    int front = 0, rear = n;

    // Push first half into stack
    for (int i = 0; i < half; i++) {
        stack[i] = q[front++];
    }

    // Pop stack into queue
    for (int i = half - 1; i >= 0; i--) {
        q[rear++] = stack[i];
    }

    // Rotate first half to rear
    for (int i = 0; i < half; i++) {
        q[rear++] = q[front++];
    }

    // Push first half again
    for (int i = 0; i < half; i++) {
        stack[i] = q[front++];
    }

    // Interleave elements
    int index = 0;
    for (int i = half - 1; i >= 0; i--) {
        q[index++] = stack[i];
        q[index++] = q[front++];
    }
}

int main() {
    int q[] = {2, 4, 3, 1};
    int n = sizeof(q) / sizeof(q[0]);

    rearrangeQueue(q, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");

    return 0;
}
