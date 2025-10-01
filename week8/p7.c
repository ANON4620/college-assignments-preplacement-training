#include <limits.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

bool isBSTUtil(struct Node* node, long long minVal, long long maxVal) {
    if (node == NULL) return true;
    if (node->data <= minVal || node->data >= maxVal) return false;
    return isBSTUtil(node->left, minVal, node->data) &&
           isBSTUtil(node->right, node->data, maxVal);
}

bool isBST(struct Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}
