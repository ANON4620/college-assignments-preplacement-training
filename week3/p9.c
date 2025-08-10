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

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* nxt = NULL;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

struct Node* addTwoNumbers(struct Node* head1, struct Node* head2) {
    head1 = reverse(head1);
    head2 = reverse(head2);
    int carry = 0;
    struct Node dummy;
    dummy.next = NULL;
    struct Node* curr = &dummy;
    while (head1 || head2 || carry) {
        int val1 = head1 ? head1->data : 0;
        int val2 = head2 ? head2->data : 0;
        int total = val1 + val2 + carry;
        carry = total / 10;
        curr->next = newNode(total % 10);
        curr = curr->next;
        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
    }
    struct Node* result = reverse(dummy.next);
    while (result && result->data == 0 && result->next) {
        struct Node* temp = result;
        result = result->next;
        free(temp);
    }
    return result;
}
