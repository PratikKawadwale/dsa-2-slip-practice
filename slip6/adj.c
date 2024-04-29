//Q 2. Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix. Display the adjacency matrix.
#include<stdio.h>
int main()
{
  int a[10][10],i,j,n;
  printf("Enter the adjecency matrix:");
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
     printf("v%d->",i,j);
    for(j=1;j<=n;j++)
    {
      printf("\t%d",a[i][j]);
    }
  }
}
