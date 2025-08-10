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

int searchKey(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return 1; // true
        head = head->next;
    }
    return 0; // false
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    int key = 3;
    if (searchKey(head, key))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
