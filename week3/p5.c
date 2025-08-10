#include <stdio.h>
#include <stdlib.h>

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

int kthFromEnd(struct Node* head, int k) {
    struct Node* first = head;
    struct Node* second = head;

    for (int i = 0; i < k; i++) {
        if (!first) return -1; // k is greater than size
        first = first->next;
    }

    while (first) {
        first = first->next;
        second = second->next;
    }

    return second ? second->data : -1;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 2;
    printf("%d\n", kthFromEnd(head, k));

    return 0;
}
