#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* deleteNode(struct Node* head, int x) {
    if (!head) return NULL;
    struct Node* temp = head;
    if (x == 1) {
        head = head->next;
        if (head) head->prev = NULL;
        free(temp);
        return head;
    }
    for (int i = 1; i < x; i++)
        temp = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp->prev)
        temp->prev->next = temp->next;
    free(temp);
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <--> ");
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
    // Creating linked list: 1 <--> 5 <--> 2 <--> 9
    struct Node* head = createNode(1);
    struct Node* n2 = createNode(5);
    struct Node* n3 = createNode(2);
    struct Node* n4 = createNode(9);

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    printf("Original list:\n");
    printList(head);

    int x = 1;
    head = deleteNode(head, x);

    printf("After deleting node at position %d:\n", x);
    printList(head);

    return 0;
}
