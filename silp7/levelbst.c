//Q 2. Write a C program which uses Binary search tree library and displays nodes at each level, and total levels in the tree.
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
struct queue
{
  struct node *data1[MAX];
  int front,rear;
}q;
Node *create(Node *root)
{
  int i,n,num;
  Node *temp,*newnode,*parent;
  printf("Enter limit:");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  { newnode=(Node*)malloc(sizeof(Node));
    printf("Enter number:");
    scanf("%d",&newnode->data);
    num=newnode->data;
    newnode->left=newnode->right=NULL;
    if(root==NULL)
    {
     root=newnode;
     continue;
    }
    temp=root;
    while(temp!=NULL)
    {
      parent=temp;
      if(num<temp->data)
       temp=temp->left;
      else
        temp=temp->right;
    }
    if(num<parent->data)
     parent->left=newnode;
    else
     parent->right=newnode;
  }return root;
}
void init()
{
  q.front=q.rear=-1;
}
int isempty()
{
  if(q.front==q.rear)
   return 1;
  else
   return 0;
}
int isfull()
{
   if(q.rear==MAX-1)
    return 1;
   else
    return 0;
}
void add(Node *temp)
{
   if(isfull())
    printf("queue is overflow");
   else
    q.data1[++q.rear]=temp;
}
Node *del()
{
  if(isempty())
   printf("queue is underflow");
  else
   return(q.data1[++q.front]);
}
void levelorder(Node *root)
{
  Node *temp,*M=NULL;
  int level=0;
  init();
  add(root);
  add(M);
  printf("level:%d->",level);
  while(!isempty())
  {
    temp=del();
    if(temp==M)
    {
     level++;
    if(!isempty())
     {
       add(M);
       printf("\nLEvel:%d->",level);
     }
   }
   else
   {
      printf("%d\t",temp->data);
      if(temp->left!=NULL)
       add(temp->left);
      if(temp->right!=NULL)
       add(temp->right);
    }
  }
}
int inorder(Node *root)
{
  Node *temp=root;
  if(temp!=NULL)
  {
    inorder(temp->left);
    printf("%d\t",temp->data);
    inorder(temp->right);
  }
}
int main()
{
  Node *root=NULL;
  root=create(root);
  inorder(root);
  printf("\n");
  levelorder(root);
}
