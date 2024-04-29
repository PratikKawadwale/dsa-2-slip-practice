//Q 2. Implement a Binary search tree (BST) library (btree.h) with operations – create, insert, postorder. Write a menu driven program that performs the above operations.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *create(Node *root)
{
  int i,n,num;
  Node *newnode,*temp,*parent;
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
      {
        temp=temp->left;
      }
      else
      {
        temp=temp->right;
      }
    }
    if(num<parent->data)
      parent->left=newnode;
    else
      parent->right=newnode;
  }return root;
}
Node *insert(Node *root)
{
  int i,n,num;
  Node *newnode,*temp,*parent;
    newnode=(Node*)malloc(sizeof(Node));
    printf("Enter number:");
    scanf("%d",&newnode->data);
    newnode->data=num;
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
void postorder(Node *root)
{
  Node *temp=root;
  if(temp!=NULL)
  {
    postorder(temp->left);
    postorder(temp->right);
    printf("%d\t",temp->data);
  }
}
int main()
{
  int ch;
  Node *root=NULL;
  do{
     printf("\n1-create\n2-insert\n3-postorder");
     printf("\nEnter choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:root=create(root);
               break;
        case 2:root=insert(root);
               break;       
        case 3:postorder(root);
               break;
     }
  }while(ch<4);
}
