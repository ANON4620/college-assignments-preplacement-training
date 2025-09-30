// Node structure
/* typedef struct Node {
    int data;
    struct Node* next;
} Node; */

// Function to create a new node
/* Node* createNode(int new_data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = new_data;
    node->next = NULL;
    return node;
} */

// Stack structure
typedef struct {
    Node* top;
    int currSize;
} myStack;

void initStack(myStack* s) {
    s->top = NULL;
    s->currSize = 0;
}

bool isEmpty(myStack* s) {
    return s->top == NULL;
}

void push(myStack* s, int x) {
    Node* node = createNode(x);
    node->next = s->top;
    s->top = node;
    s->currSize++;
}

void pop(myStack* s) {
    if (isEmpty(s)) return;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->currSize--;
}

int peek(myStack* s) {
    if (isEmpty(s)) return -1;
    return s->top->data;
}

int size(myStack* s) {
    return s->currSize;
}