//different functions
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int treeHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int nodeCount(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

int leafNodeCount(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return leafNodeCount(root->left) + leafNodeCount(root->right);
}

void printLeaves(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void mirrorTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct Node* insertNode(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, key, choice;

   
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insertNode(root, key);
    }

   
    do {
        printf("\nMenu:\n");
        printf("1. Display Tree Height\n");
        printf("2. Display Total Node Count\n");
        printf("3. Display Left Node Count\n");
        printf("4. Display Leaf Nodes\n");
        printf("5. Mirror Tree\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Height of tree: %d\n", treeHeight(root));
                break;
            case 2:
                printf("Total node count: %d\n", nodeCount(root));
                break;
            case 3:
                printf("Left node count: %d\n", leafNodeCount(root));
                break;
            case 4:
                printf("Leaf nodes: ");
                printLeaves(root);
                printf("\n");
                break;
            case 5:
                mirrorTree(root);
                printf("Tree has been mirrored.\n");
                break;
            case 6:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
