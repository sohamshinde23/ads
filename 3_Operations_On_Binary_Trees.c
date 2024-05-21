#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct TreeNode *insertNode(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int countNodes(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void printLeafNodes(struct TreeNode *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int findHeight(struct TreeNode *root)
{
    if (root == NULL)
        return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void mirrorTree(struct TreeNode *root)
{
    if (root == NULL)
        return;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void deallocateTree(struct TreeNode *root)
{
    if (root == NULL)
        return;
    deallocateTree(root->left);
    deallocateTree(root->right);
    free(root);
}

int main()
{
    struct TreeNode *root = NULL;
    int choice, value;

    printf("Binary Tree Operations Menu:\n");
    printf("1. Insert Node\n");
    printf("2. Count Total Nodes\n");
    printf("3. Count Leaf Nodes\n");
    printf("4. Print Leaf Nodes\n");
    printf("5. Find Height of Tree\n");
    printf("6. Display Mirror Image of Tree\n");
    printf("7. Exit\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("Total number of nodes in the tree: %d\n", countNodes(root));
            break;
        case 3:
            printf("Total number of leaf nodes in the tree: %d\n", countLeafNodes(root));
            break;
        case 4:
            printf("Leaf nodes in the tree: ");
            printLeafNodes(root);
            printf("\n");
            break;
        case 5:
            printf("Height of the tree: %d\n", findHeight(root));
            break;
        case 6:
            printf("Mirror Image of the tree:\n");
            mirrorTree(root);
            printLeafNodes(root);
            printf("\n");
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 7);

    deallocateTree(root);

    return 0;
}
