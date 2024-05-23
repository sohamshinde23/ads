//non recursive using stack 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}node;
 typedef struct stack
{
    struct node *data[30];
    int top;
}stack;
typedef struct stacknode
{
    node *data;
    int flag;
}stacknode;

void init (stack *p)
{
    p->top=-1;
}
int isempty(stack *p)
{
    if(p->top==-1)
     return 1;
     return 0;
}
 int isfull(stack *p)
 {
    if(p-> top==29)
    return 1;
    return 0;
 }
 void push(stack *p,node* x)
 {
    p->top ++;
    p->data[p->top]=x;
 }
node* pop(stack *p)
{
   node* x=p->data[p->top];
    p->top--;
    return x;
}

node *create()
{
    node *p;
    int x;
    printf("\nEnter data (-1for data):");
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
void preorder_non_recursive(node *p)
{
    stack s;
    init(&s);
    int x;
    while(p!=NULL)
    {
        printf("--%d--",p->data);
       
        push(&s,p);
        p=p->left;
    }
    while(!isempty(&s))
    {
        p=pop(&s);
        p=p->right;
        while(p!=NULL)
        {
            printf("--%d--",p->data);
            push(&s,p);
            p=p->left;
        
        }
    }
}

void inorder_non_recursive(node *p)
{
    stack s;
    init(&s);
    while(p!=NULL)
    {
        push(&s,p);
        p=p->left;
    }
    while(!isempty(&s))
    {
        p=pop(&s);
        printf("--%d--",p->data);
        p=p->right;
        while(p!=NULL)
        {
            push(&s,p);
            p=p->left;
        }
    }
}

void postorder_non_recursion(node *p)
{
   stack s,s1;
   init(&s);
   init(&s1);

   while(p!= NULL)
   {
    push(&s,p);
    push(&s1,NULL);
    p=p->left;

   }
   while(!isempty(&s))
   {
    p=pop(&s);
    if(pop(&s1)==NULL)
    {
        push(&s,p);
        push(&s1,(node*)1);
        p=p->right;
        while(p!=NULL)
        {
            push(&s,p);
            push(&s1,NULL);
            p=p->left;
        }
    }
    else 
    printf("--%d--",p->data);
   }   
}
int main()
{   int x;
    node *p;
    p=create();
    printf("\npreorder:");
    preorder_non_recursive(p);
    printf("\ninorder:");
     inorder_non_recursive(p);
    printf("\npostorder:");
    postorder_non_recursion(p);
}