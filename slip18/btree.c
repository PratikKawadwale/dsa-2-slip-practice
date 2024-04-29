//Q 2. Implement a Binary search tree (BST) library (btree.h) with operations – create, insert,inorder. Write a menu driven program that performs the above operations.
#include<stdio.h>
#include<stdlib.h>
#define Memory (struct node *)malloc(sizeof(struct node))
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *create(Node *root)
{
  int i,n,num;
  Node *temp,*newnode,*parent;
  printf("Enter  limit:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     newnode=Memory;
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
Node *insert(Node *root)
{
  int n,num;
  Node *temp,*newnode,*parent;
     newnode=Memory;
     printf("Enter number:");
     scanf("%d",&newnode->data);
     num=newnode->data;
     newnode->left=newnode->right=NULL;
     if(root==NULL)
     {
       root=newnode;
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
int main()
{
  int ch;
  Node *root=NULL;
  do{
   printf("\n1-create\n2-Insert\n3-inorder");
   printf("\nEnter choice:");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1:root=create(root);
             break;
      case 2:root=insert(root);
             break;
      case 3:inorder(root);
             break;
   }
  }while(ch<4);
}
