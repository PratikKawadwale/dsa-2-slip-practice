//Q 2. Write a C program which uses Binary search tree library and displays nodes at each level, and total levels in the tree.
#include<stdio.h>
#include<stdlib.h>
#define Max 10
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
struct queue
{
  Node *data1[Max];
  int front,rear;
}q;
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
  if(q.rear==Max-1)
    return 1;
  else
    return 0;
}
int addq(Node *temp)
{ 
   if(isfull())
    printf("Queue is overflow");
  else
    q.data1[++q.rear]=temp;
}
Node *del()
{
   if(isempty())
    printf("Queue is underflow");
   else
    return(q.data1[++q.front]);
}
Node *create(Node *root)
{
  int i,n,num;
  Node *temp,*newnode,*parent;
  printf("Enter limit:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    newnode=(Node*)malloc(sizeof(Node));
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
void levelorder(Node *root)
{
 Node *temp,*M=NULL;
 int level=0;
 addq(root);
 addq(M);
 printf("level%d->",level);
 while(!isempty())
 {
    temp=del();
    if(temp==M)
    {
       level++;
       if(!isempty())
       {
         addq(M);
         printf("\nlevel%d->",level);
       }
    }
    else
    {
      printf("%d\t",temp->data);
      if(temp->left!=NULL)
       addq(temp->left);
      if(temp->right!=NULL)
       addq(temp->right);
    }
 }
}
void inorder(Node *root)
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
  printf("\n");
  inorder(root);
   printf("\n");
  levelorder(root); 
}
