struct Node* LCA(struct Node* root, struct Node* n1, struct Node* n2) {
    if (root == NULL) return NULL;

    if (n1->data < root->data && n2->data < root->data)
        return LCA(root->left, n1, n2);
    else if (n1->data > root->data && n2->data > root->data)
        return LCA(root->right, n1, n2);
    else
        return root;
}
