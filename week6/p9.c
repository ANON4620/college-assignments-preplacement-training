#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* data;
    int front, rear, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (Point*)malloc(sizeof(Point) * capacity);
    q->front = q->rear = 0;
    q->capacity = capacity;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Point p) {
    q->data[q->rear++] = p;
}

Point dequeue(Queue* q) {
    return q->data[q->front++];
}

int orangesRotting(int** mat, int n, int m) {
    int fresh = 0, time = 0;
    Queue* q = createQueue(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2) {
                enqueue(q, (Point){i, j});
            } else if (mat[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (!isEmpty(q)) {
        int size = q->rear - q->front;
        int changed = 0;

        for (int i = 0; i < size; i++) {
            Point p = dequeue(q);
            for (int d = 0; d < 4; d++) {
                int nx = p.x + dirs[d][0];
                int ny = p.y + dirs[d][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1) {
                    mat[nx][ny] = 2;
                    fresh--;
                    enqueue(q, (Point){nx, ny});
                    changed = 1;
                }
            }
        }
        if (changed) time++;
    }

    free(q->data);
    free(q);
    return fresh == 0 ? time : -1;
}
