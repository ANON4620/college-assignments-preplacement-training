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

bool removeCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    bool cycleFound = false;

    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cycleFound = true;
            break;
        }
    }

    if (!cycleFound) return true; // No cycle present

    // Find start of cycle
    slow = head;
    struct Node* prev = NULL;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Break the cycle
    prev->next = NULL;
    return true;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(4);
    head->next->next->next = head->next; // loop to 2nd node

    printf("%s\n", removeCycle(head) ? "true" : "false");
    return 0;
}
