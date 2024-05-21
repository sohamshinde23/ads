#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    struct Node* stack[100]; 
// array stack of size 100 to act as a stack for storing nodes during traversal. 
    int top = -1;
    struct Node* current = root;
//  set -1 as empty stack
// current is initialized to root, which represents the current node being processed
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
//  loop traverses the left subtree of the current node. 
//  It keeps pushing nodes onto the stack as long as there are left children
        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
// left subtree is fully explored, the current node is popped from the stack, printed
// then the pointer is moved to its right child
// The process continues until all nodes have been visited and printed.
// iterative approach
}

void preorder(struct Node* root) {
    struct Node* stack[100]; 
    int top = -1;

    if (root != NULL)
        stack[++top] = root;
// If the root node is not NULL and root is pusedd onto stack

    while (top != -1) { //  loop continues until the stack becomes empty
        struct Node* current = stack[top--];
        printf("%d ", current->data);
// The top node is popped from the stack and its data is printed. 
// This represents the "visit" step in preorder traversal, 
// where the current node is processed before its children.
        if (current->right)
            stack[++top] = current->right;
        if (current->left)
            stack[++top] = current->left;
    }
// If the current node has a right child, it is pushed onto the stack first 
// if the current node has a left child, it is pushed onto the stack.
// This ensures that the left subtree of each node is fully explored before the right subtree.
}
// iterative approach

void postorder(struct Node* root) {
    struct Node* stack[100]; 
    int top = -1;
    struct Node* lastVisited = NULL;

    do {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
//  loop traverses the left subtree of the current node.          
//  It keeps pushing nodes onto the stack as long as there are left children.
        while (top != -1 && stack[top]->right == lastVisited) {
            lastVisited = stack[top--];
            printf("%d ", lastVisited->data);
        }
// After exploring the left subtree, this loop checks if the top node in the stack has a right child that has already been visited
// if so, it means that the right subtree has already been explored, 
// so the top node can be popped and printed. 
        if (top != -1) {
            root = stack[top]->right;
        }
    } while (top != -1);
}

void displayMenu() {
    printf("\n1. Inorder traversal\n");
    printf("2. Preorder traversal\n");
    printf("3. Postorder traversal\n");
    printf("4. Exit\n");
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}