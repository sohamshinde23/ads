#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//initializes its data with the provided value, and sets its left and right pointers to NULL

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}
// takes two arguments: a pointer to the root node of bst (root) and the integer value (data).
// root pointer is NULL, which means the tree is empty.
// If the tree is empty, it calls the createNode() function
// This newly created node becomes the root of the tree.
// data is less than the current node's data, it recursively calls the insert() function on the left subtree (root->left) to insert the data into the left subtree.
// and vice versa

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

// function takes two arguments: a pointer to the root node of bst (root) and the integer key that to be searched
// if the current node (root) is NULL, 
// if null tree is empty or end of a branch. 
// if the current node's data matches the key, it returns the current node (root). 
// current node's data is less than the integer, 
// it means that the key, if present, must be in the right 
// recursively calls the search() function on the right subtree with same key i.e integer
// eles it will check for the left 

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

// takes two arguments: a pointer to the root node of bst (root) and the integer key that needs to be deleted (key).
// checks if the current node (root) is NULL then nothing to delete
// key < the current node's data, it means the key, if present, must be in the left subtree. So, it recursively calls the deleteNode() function
// if key > root then it goes in the right subtree
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
//  If the node has no left child, we replace the node with its right child and return the right child pointer.
//  If the node has no right child, we replace the node with its left child and return the left child pointer.
//  If the node has both left and right children, we find the minimum value node in the right subtree of the current node (temp)
        
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
//  if minimum value node found in the right subtree (temp) and copy its data to the current node. Then, we recursively call the deleteNode()
    return root;
}


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL)
                    printf("Element found in BST.\n");
                else
                    printf("Element not found in BST.\n");
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Node deleted successfully.\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}