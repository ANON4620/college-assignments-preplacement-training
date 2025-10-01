int height(struct Node* node) {
    if (node == NULL)
        return -1;
    int left_height = height(node->left);
    int right_height = height(node->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}
