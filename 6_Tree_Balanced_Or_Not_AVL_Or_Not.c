#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the height of a tree
int height(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to check if the tree is balanced
int isBalanced(Node* root) {
    if (root == NULL) return 1;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    
    return 0;
}

// Function to perform left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

// Function to perform right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

// Function to check AVL balance and rotation cases
void checkAVL(Node* root) {
    if (root == NULL) return;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int balanceFactor = leftHeight - rightHeight;

    if (balanceFactor > 1) {
        // Left Heavy
        printf("Tree is not AVL balanced. Left rotation needed.\n");
        if (height(root->left->left) >= height(root->left->right))
            printf("Rotation Case: Left-Left\n");
        else
            printf("Rotation Case: Left-Right\n");
    } else if (balanceFactor < -1) {
        // Right Heavy
        printf("Tree is not AVL balanced. Right rotation needed.\n");
        if (height(root->right->right) >= height(root->right->left))
            printf("Rotation Case: Right-Right\n");
        else
            printf("Rotation Case: Right-Left\n");
    } else {
        printf("Tree is AVL balanced.\n");
    }
}

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to display menu
void displayMenu() {
    printf("\nMENU:\n");
    printf("1. Insert a number into the Binary Tree\n");
    printf("2. Check if the tree is balanced\n");
    printf("3. Check if the tree is AVL balanced\n");
    printf("4. Exit\n");
}

int main() {
    Node* root = NULL;
    int choice, num;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert into the Binary Tree: ");
                scanf("%d", &num);
                root = insertNode(root, num);
                break;
            case 2:
                printf("Checking if the tree is balanced...\n");
                if (isBalanced(root))
                    printf("Tree is balanced.\n");
                else
                    printf("Tree is not balanced.\n");
                break;
            case 3:
                printf("Checking if the tree is AVL balanced...\n");
                checkAVL(root);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
