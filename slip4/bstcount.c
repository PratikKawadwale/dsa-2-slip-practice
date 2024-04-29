//Write a program which uses binary search tree library and counts the total nodes and totalleaf nodes in the tree. int countLeaf(T) – returns the total number of leaf nodes from BST.
#include<stdio.h>
#include<stdlib.h>
#define Memory (struct node*)malloc(sizeof(struct node))
typedef struct node
{
   int data;
   struct node *left,*right;
}Node;
Node *create(Node *root)
{
  int i,n,num;
  Node *temp,*newnode,*parent;
  printf("Enter limit:");
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
  }
  return root;
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
   static int c=0;
   Node *temp=root;
   if(temp!=NULL)
   {
     c++;
     count(temp->left);
     count(temp->right);
   }
   return c;
}
int countleaf(Node *root)
{
   static int c=0;
   Node *temp=root;
   if(temp!=NULL)
   {
     if(temp->left==NULL && temp->right==NULL)
   
       c++;
       countleaf(temp->left);
       countleaf(temp->right);
    }   
   return c;
}
int main()
{
 int ch,c;
 Node *root=NULL;
 do{
 printf("\n1-create\n2-inorder\n3-count\n4-countleaf");
 printf("\nEnter choice");
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:root=create(root);
          break;
   case 2:inorder(root);
          break;
   case 3:c=count(root);
          printf("count:%d",c);
          break;
   case 4:c=countleaf(root);
          printf("leafnode:%d",c);
          break;
 }
 }while(ch<5);
}
