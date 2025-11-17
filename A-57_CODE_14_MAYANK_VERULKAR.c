#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// ========== TRAVERSALS ==========

// Inorder (LNR)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder (NLR)
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder (LRN)
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// BFS (Level order)
void bfs(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* cur = queue[front++];
        printf("%d ", cur->data);

        if (cur->left) queue[rear++] = cur->left;
        if (cur->right) queue[rear++] = cur->right;
    }
}

// DFS using stack
void dfs(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node* cur = stack[top--];
        printf("%d ", cur->data);

        if (cur->right) stack[++top] = cur->right;
        if (cur->left) stack[++top] = cur->left;
    }
}

// ========== MIRROR TREE ==========

struct Node* mirror(struct Node* root) {
    if (root == NULL) return NULL;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

    return root;
}

// ========== FINDING FAMILY RELATIONS ==========

// Find parent of a node
struct Node* findParent(struct Node* root, int key, struct Node* parent) {
    if (root == NULL) return NULL;
    if (root->data == key) return parent;

    if (key < root->data)
        return findParent(root->left, key, root);
    else
        return findParent(root->right, key, root);
}

// Find node
struct Node* findNode(struct Node* root, int key) {
    if (!root) return NULL;

    if (root->data == key)
        return root;

    else if (key < root->data)
        return findNode(root->left, key);

    return findNode(root->right, key);
}

// Children
void findChildren(struct Node* root, int key) {
    struct Node* node = findNode(root, key);

    if (!node) {
        printf("Node not found.\n");
        return;
    }

    printf("Children of %d: ", key);
    if (node->left) printf("Left: %d ", node->left->data);
    if (node->right) printf("Right: %d ", node->right->data);
    if (!node->left && !node->right) printf("No children.");
    printf("\n");
}

// Sibling
void findSibling(struct Node* root, int key) {
    struct Node* parent = findParent(root, key, NULL);

    if (!parent) {
        printf("No sibling (root node).\n");
        return;
    }

    if (parent->left && parent->left->data != key)
        printf("Sibling: %d\n", parent->left->data);
    else if (parent->right && parent->right->data != key)
        printf("Sibling: %d\n", parent->right->data);
    else
        printf("No sibling.\n");
}

// Grandparent
void findGrandParent(struct Node* root, int key) {
    struct Node* parent = findParent(root, key, NULL);
    if (!parent) {
        printf("No parent.\n");
        return;
    }
    struct Node* gp = findParent(root, parent->data, NULL);
    if (!gp) printf("No grandparent.\n");
    else printf("Grandparent: %d\n", gp->data);
}

// Uncle node
void findUncle(struct Node* root, int key) {
    struct Node* parent = findParent(root, key, NULL);
    if (!parent) {
        printf("No parent → no uncle.\n");
        return;
    }
    struct Node* gp = findParent(root, parent->data, NULL);
    if (!gp) {
        printf("No grandparent → no uncle.\n");
        return;
    }

    if (gp->left && gp->left != parent)
        printf("Uncle: %d\n", gp->left->data);
    else if (gp->right && gp->right != parent)
        printf("Uncle: %d\n", gp->right->data);
    else
        printf("No uncle.\n");
}


// ================= MAIN MENU =================

int main() {
    int choice, data, key;

    while (1) {
        printf("\n=== BST MENU ===\n");
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. BFS\n");
        printf("6. DFS\n");
        printf("7. Mirror tree\n");
        printf("8. Find children\n");
        printf("9. Find sibling\n");
        printf("10. Find parent\n");
        printf("11. Find grandparent\n");
        printf("12. Find uncle\n");
        printf("13. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                inorder(root);
                printf("\n");
                break;

            case 3:
                preorder(root);
                printf("\n");
                break;

            case 4:
                postorder(root);
                printf("\n");
                break;

            case 5:
                bfs(root);
                printf("\n");
                break;

            case 6:
                dfs(root);
                printf("\n");
                break;

            case 7:
                root = mirror(root);
                printf("Tree mirrored.\n");
                break;

            case 8:
                printf("Enter node: ");
                scanf("%d", &key);
                findChildren(root, key);
                break;

            case 9:
                printf("Enter node: ");
                scanf("%d", &key);
                findSibling(root, key);
                break;

            case 10:
                printf("Enter node: ");
                scanf("%d", &key);
                struct Node* parent = findParent(root, key, NULL);
                if (parent) printf("Parent: %d\n", parent->data);
                else printf("No parent (root).\n");
                break;

            case 11:
                printf("Enter node: ");
                scanf("%d", &key);
                findGrandParent(root, key);
                break;

            case 12:
                printf("Enter node: ");
                scanf("%d", &key);
                findUncle(root, key);
                break;

            case 13:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
