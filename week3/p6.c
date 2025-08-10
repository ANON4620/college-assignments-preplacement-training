#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

bool hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    // Example: 1 -> 3 -> 4, pos = 2
    struct Node* head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(4);
    head->next->next->next = head->next; // loop to node 2

    printf("%s\n", hasCycle(head) ? "true" : "false");
    return 0;
}
