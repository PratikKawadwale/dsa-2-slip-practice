//Q 1. Write a C program that accepts the vertices and edges of a graph. Create adjacency list anddisplay the adjacency list.
#include<stdio.h>
#include<stdlib.h>
#define Memory (struct node*)malloc(sizeof(struct node))
struct node
{
  int data;
  struct node *next;
};
struct node *head[10];
void create(int a[10][10],int n)
{
  int i,j;
  struct node *temp,*newnode;
  for(i=1;i<=n;i++)
  { 
    head[i]=NULL;
    for(j=1;j<=n;j++)
    {
     if(a[i][j]==1)
     {
      newnode=Memory;
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
  int i;
  struct node *temp;
  for(i=1;i<=n;i++)
  {
    printf("\nhead%d->",i);
    for(temp=head[i];temp!=NULL;temp=temp->next)
    {
      printf("%d->",temp->data);
    }
     printf("NULL");
  }
}
int main()
{
  int a[10][10],i,j,n;
  printf("Enter adjecency matrix:");
  scanf("%d",&n);
  printf("Enter edge between 0/1 format"); 
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  create(a,n);
  disp(n);
}
