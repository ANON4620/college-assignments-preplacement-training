#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->bottom = NULL;
    return node;
}

// Merge two sorted bottom lists
struct Node* merge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    struct Node* result;
    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL; // next pointer not used in flattened list
    return result;
}

// Recursively flatten the list
struct Node* flatten(struct Node* root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

// Print bottom list
void printList(struct Node* node) {
    while (node) {
        printf("%d ", node->data);
        node = node->bottom;
    }
    printf("\n");
}

// Example usage
int main() {
    // Creating example linked list:
    // 5 -> 10 -> 19 -> 28
    // |    |     |     |
    // 7    20    22    35
    // |          |     |
    // 8          50    40
    // |                |
    // 30               45

    struct Node* head = newNode(5);
    head->bottom = newNode(7);
    head->bottom->bottom = newNode(8);
    head->bottom->bottom->bottom = newNode(30);

    head->next = newNode(10);
    head->next->bottom = newNode(20);

    head->next->next = newNode(19);
    head->next->next->bottom = newNode(22);
    head->next->next->bottom->bottom = newNode(50);

    head->next->next->next = newNode(28);
    head->next
