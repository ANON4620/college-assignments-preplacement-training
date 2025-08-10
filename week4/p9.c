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

struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    struct Node* p1 = head1;
    struct Node* p2 = head2;
    while (p1 != p2) {
        p1 = p1 ? p1->next : head2;
        p2 = p2 ? p2->next : head1;
    }
    return p1;
}

int main() {
    struct Node* common = newNode(8);
    common->next = newNode(4);
    common->next->next = newNode(5);

    struct Node* head1 = newNode(4);
    head1->next = newNode(1);
    head1->next->next = common;

    struct Node* head2 = newNode(5);
    head2->next = newNode(6);
    head2->next->next = newNode(1);
    head2->next->next->next = common;

    struct Node* intersect = getIntersectionNode(head1, head2);
    if (intersect) printf("%d\n", intersect->data);
    return 0;
}
