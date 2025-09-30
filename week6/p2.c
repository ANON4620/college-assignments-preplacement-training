// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int currSize;
} myQueue;

// Function to create a new node
Node* createNode(int new_data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = new_data;
    node->next = NULL;
    return node;
}

// Initialize queue
void initQueue(myQueue* q) {
    q->front = q->rear = NULL;
    q->currSize = 0;
}

bool isEmpty(myQueue* q) {
    return q->currSize == 0;
}

void enqueue(myQueue* q, int x) {
    Node* newNode = createNode(x);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->currSize++;
}

void dequeue(myQueue* q) {
    if (isEmpty(q)) return;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->currSize--;
}

int getFront(myQueue* q) {
    if (isEmpty(q)) return -1;
    return q->front->data;
}

int size(myQueue* q) {
    return q->currSize;
}