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

int isCircular(struct Node* head) {
    if (!head) return 1;
    struct Node* temp = head->next;
    while (temp && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

int main() {
    struct Node* head = newNode(5);
    head->next = newNode(2);
    head->next->next = head;
    printf("%s\n", isCircular(head) ? "true" : "false");

    struct Node* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = NULL;
    printf("%s\n", isCircular(head2) ? "true" : "false");

    return 0;
}
