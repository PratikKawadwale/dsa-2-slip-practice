//Q 2. Write a program which uses binary search tree library and counts the total nodes and total leaf nodes in the tree. int count Leaf(T) – returns the total number of leaf nodes from BST
#include<stdio.h>
#include<stdlib.h>
#define memory (struct node*)malloc(sizeof(struct node))
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *create(Node *root)
{
  Node *newnode,*temp,*parent;
  int i,n,num;
  printf("Enter limit");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    newnode=memory;
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
          {
            temp=temp->left;
          }
         else
         {
           temp=temp->right;
         }
    }
     if(num<parent->data)
       {
        parent->left=newnode;
      }
    else
    {
        parent->right=newnode;
    }
  }return root;
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
int count(Node *root)
{
  Node *temp=root;
   static int c=0;
  if(temp!=NULL)
  {
    c++;
    count(temp->left);
    count(temp->right);
  }return c;
}
int leafnode(Node *root)
{
  Node *temp=root;
   static int c=0;
  if(temp!=NULL)
  {
    if(temp->left==NULL && temp->right==NULL)
    c++;
    leafnode(temp->left);
    leafnode(temp->right);
  }return c;
}
int main()
{
  Node *root=NULL;
  int ch,c;
  do{
    printf("\n1-create\n2-inorder\n3-count\n4-leafnode");
    printf("\nEnter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:root=create(root);
             break;
      case 2:inorder(root);
             break;
      case 3:c=count(root);
             printf("count=%d",c);
             break;
      case 4:c=leafnode(root);
             printf("leafnode=%d",c);
             break;             
    }
  }while(ch<5);
}
