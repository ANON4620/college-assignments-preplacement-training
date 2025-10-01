int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node, int* diameter) {
    if (node == NULL) return -1;

    int left_height = height(node->left, diameter);
    int right_height = height(node->right, diameter);

    *diameter = max(*diameter, left_height + right_height + 2);

    return max(left_height, right_height) + 1;
}

int diameter(struct Node* root) {
    int dia = 0;
    height(root, &dia);
    return dia;
}
