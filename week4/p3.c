#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* reverseDLL(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* curr = head;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) head = temp->prev;
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(3);
    struct Node* n2 = createNode(4);
    struct Node* n3 = createNode(5);

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;

    printf("Original list:\n");
    printList(head);

    head = reverseDLL(head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}
