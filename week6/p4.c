void push(struct sNode** top_ref, int new_data) {
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));
    if (!new_node) {
        printf("Stack overflow\n");
        exit(1);
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct sNode** top_ref) {
    if (*top_ref == NULL)
        return -1;

    struct sNode* temp = *top_ref;
    int popped = temp->data;
    *top_ref = temp->next;
    free(temp);
    return popped;
}
