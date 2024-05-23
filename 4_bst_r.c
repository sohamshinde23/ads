//bst insertion deletion serching
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create(int data) {
    node *p;
    p = (node *)malloc(sizeof(node));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

node *insert(node *p, int key) {
    if (p == NULL) {
        return create(key);
    }

    if (p->data > key) {
        p->left = insert(p->left, key);
    } else if (key > p->data) {
        p->right = insert(p->right, key);
    }
    return p;
}

void inorder(node *p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d-- ", p->data);
        inorder(p->right);
    }
}

int search(node *p, int key) {
    if (p == NULL) {
        return 0;
    }

    if (key == p->data) {
        return 1; // Key found
    } else if (key < p->data) {
        return search(p->left, key);
    } else {
        return search(p->right, key);
    }
}

node *findmin(node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

node *delete_node(node *root, int key) {
    node *temp;
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = delete_node(root->left, key);
    } else if (key > root->data) {
        root->right = delete_node(root->right, key);
    } else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        } else {
            temp = findmin(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    int x;
    int data;
    node *p = NULL;
    int b, c;

    printf("Enter the number of nodes to be inserted: ");
    scanf("%d", &x);

    for (int i = 0; i < x; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);
        p = insert(p, data);
    }

    while (1) {
        printf("\n**MENU**");
        printf("\n1. Insert element into BST");
        printf("\n2. Delete element from BST");
        printf("\n3. Search element in BST");
        printf("\n4. Inorder of BST");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &b);

        switch (b) {
            case 1:
                printf("\nEnter the number to be inserted into BST: ");
                scanf("%d", &c);
                p = insert(p, c); 
                printf("%d is inserted into BST\n", c);
                break;

            case 2:
                printf("\nEnter the number to be deleted from BST: ");
                scanf("%d", &c);
                p = delete_node(p, c); 
                printf("%d is deleted from BST\n", c);
                break;

            case 3:
                printf("\nEnter the number to search in BST: ");
                scanf("%d", &c);
                if (search(p, c)) {
                    printf("%d is found in BST\n", c);
                } else {
                    printf("%d is not found in BST\n", c);
                }
                break;

            case 4:
                printf("\nInorder traversal: ");
                inorder(p);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}

