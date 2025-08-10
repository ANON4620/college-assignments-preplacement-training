#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

struct Node* addPolynomial(struct Node* p1, struct Node* p2) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    while (p1 && p2) {
        struct Node* temp = NULL;
        if (p1->pow == p2->pow) {
            temp = createNode(p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            temp = createNode(p1->coeff, p1->pow);
            p1 = p1->next;
        } else {
            temp = createNode(p2->coeff, p2->pow);
            p2 = p2->next;
        }

        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    while (p1) {
        tail->next = createNode(p1->coeff, p1->pow);
        tail = tail->next;
        p1 = p1->next;
    }

    while (p2) {
        tail->next = createNode(p2->coeff, p2->pow);
        tail = tail->next;
        p2 = p2->next;
    }

    return head;
}

void printPolynomial(struct Node* head) {
    while (head) {
        printf("%dx^%d", head->coeff, head->pow);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = createNode(1, 3);
    poly1->next = createNode(2, 2);

    struct Node* poly2 = createNode(3, 3);
    poly2->next = createNode(4, 2);

    struct Node* result = addPolynomial(poly1, poly2);
    printPolynomial(result);

    return 0;
}
