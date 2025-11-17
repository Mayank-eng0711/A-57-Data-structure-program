// Find minimum element
struct Node* findMin(struct Node* root) {
    if (root == NULL) return NULL;

    struct Node* current = root;
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Find maximum element
struct Node* findMax(struct Node* root) {
    if (root == NULL) return NULL;

    struct Node* current = root;
    while (current->right != NULL)
        current = current->right;

    return current;
}
