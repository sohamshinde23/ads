//tree tranversal by recursion
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
   struct node *left;
   struct node *right;
}node;
node *create()
{
    node *p;
    int x;
    printf("\nEnter data (-1 for no data):");
    scanf("%d",&x);
    if(x==-1)
    return NULL;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("\nEnter left child of %d",x);
    p->left=create();
    printf("\n Enter the right child of %d",x);
    p->right=create();
    return p;
}
void preorder(node *p)
{
    if(p!=NULL)
    {
        printf("%d-",p->data);
        preorder(p->left);
        preorder(p->right);
    }
    
}
void inorder(node *p)
{
    if(p!=NULL)
    {
    inorder(p->left);
    printf("%d-",p->data);
    inorder(p->right);
    }
}
void postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d-",p->data);
    }
   
}
int main()
{
    node *p;
    p=create();
    printf("\npreorder:");
    preorder(p);
    printf("\ninorder:");
    inorder(p);
    printf("\n postorder:");
    postorder(p);
}
