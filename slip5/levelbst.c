//binary search tree level order display
#include<stdio.h>
#include<stdlib.h>
#define Memory (struct node *)malloc(sizeof(struct node)) 
#define MAX 50
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
struct que
{
  Node *data1[MAX];
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
    if(q.rear==MAX-1)
      return 1;
    else
     return 0;
}
void add(Node *temp)
{
  if(isfull())
    printf("Queue is overfloow");
  else
  {
     q.data1[++q.rear]=temp;
  }
}
Node *delq()
{
  if(isempty())
     printf("Queure is underflow");
  else
     return(q.data1[++q.front]);
}
Node *create(Node *root)
{
  Node *temp,*newnode,*parent;
  int i,n,num;
  printf("Enter limit");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    newnode=Memory;
    printf("Enter number");
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
  init();
  add(root);
  add(M);
  printf("\nLevel:%d-->",level);
    while(!isempty())
    {
      temp=delq();
      if(temp==M)
      {
        level++;
        if(!isempty())
        {
           add(M);
           printf("\nLevel:%d-->",level);
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
