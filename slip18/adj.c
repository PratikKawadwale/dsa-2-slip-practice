//Q 1. Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix. Display the adjacency matrix.
#include<stdio.h>
int main()
{
   int i,n,j,a[10][10];
   printf("Enter adj matrix limit:");
   scanf("%d",&n);
   printf("Enter edge bet 0/1 format:");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&a[i][j]);
     }
   }
  for(i=1;i<=n;i++)
   {
      printf("\n");
      printf("v%d\t",i,j);
     for(j=1;j<=n;j++)
     {
       printf("%d\t",a[i][j]);
     }
   }
}
