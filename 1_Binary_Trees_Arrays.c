// Binary Tree Using Array

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int tree[MAX_SIZE];
void initializeTree()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        tree[i] = -1;
    }
}

void insertNode(int value, int index)
{
    tree[index] = value;
}

void displayTree()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (tree[i] != -1)
        {
            printf("%d ", tree[i]);
        }
    }
    printf("\n");
}

int main()
{
    initializeTree();
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values of nodes: ");
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        insertNode(value, i);
    }
    printf("Binary Tree Using Array: ");
    displayTree();
    return 0;
}
