//Q 2. Write a C program that accepts the vertices and edges of a graph. Create adjacency list and display the adjacency list.
#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{ 
 int data;
struct node*next; 
}Node;
Node *head[10];
Node *create(int a[10][10],int n)
{
  int i,j;
  Node *temp,*newnode;
  for(i=1;i<=n;i++)
  {
    head[i]=NULL;
    for(j=1;j<=n;j++)
    {
      if(a[i][j]==1)
      {
      newnode=(Node*)malloc(sizeof(Node));
      newnode->data=j;
      newnode->next=NULL;
      if(head[i]==NULL)
      {
        head[i]=temp=newnode;
      }
      else
      {
         temp->next=newnode;
         temp=newnode;
      }
    }
    }
  }
}
void disp(int n)
{
  Node *temp;
  int i;
  for(i=1;i<=n;i++)
  {
    printf("head%d->",i);
    for(temp=head[i];temp!=NULL;temp=temp->next)
    {
      printf("%d->",temp->data);
    }
    printf("NULL");
    printf("\n");
    }
}
int main()
{
  int i,j,n,a[10][10];
  printf("Enter the adj matrix:");
  scanf("%d",&n);
  printf("Enter edge between 0/1 format");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  for(i=1;i<=n;i++)
  {  printf("\n");
     printf("v%d\t",i);
    for(j=1;j<=n;j++)
    {
      printf("%d\t",a[i][j]);
    }
  }
  printf("\n");
  create(a,n);
  disp(n);
  
}
