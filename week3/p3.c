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

struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL) return NULL;

    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* prev = head;
    for (int i = 1; i < x - 1 && prev != NULL; i++)
        prev = prev->next;

    if (prev != NULL && prev->next != NULL) {
        struct Node* temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(4);

    head = deleteNode(head, 3);
    printList(head);
    return 0;
}
