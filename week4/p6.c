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

struct Node* sortedInsert(struct Node* head, int data) {
    struct Node* node = newNode(data);
    if (!head) {
        node->next = node;
        return node;
    }
    struct Node* curr = head;
    while (1) {
        if (curr->data <= data && data <= curr->next->data) break;
        if (curr->data > curr->next->data && (data >= curr->data || data <= curr->next->data)) break;
        curr = curr->next;
        if (curr == head) break;
    }
    node->next = curr->next;
    curr->next = node;
    return head;
}

void printList(struct Node* head) {
    if (head) {
        struct Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(4);
    head->next->next = newNode(7);
    head->next->next->next = newNode(9);
    head->next->next->next->next = head;
    head = sortedInsert(head, 5);
    printList(head);
    return 0;
}
