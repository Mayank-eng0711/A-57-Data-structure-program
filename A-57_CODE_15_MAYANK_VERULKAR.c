void printInRange(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    // If root->data is greater than low, explore left subtree
    if (root->data > low)
        printInRange(root->left, low, high);

    // If root is within range, print it
    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    // If root->data is less than high, explore right subtree
    if (root->data < high)
        printInRange(root->right, low, high);
}
