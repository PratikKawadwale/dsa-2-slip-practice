//Q 2. Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix. Display the adjacency matrix
#include<stdio.h>
int main()
{
   int i,n,j,a[10][10];
   printf("Enter the adjecency graph vertex:");
   scanf("%d",&n);
   printf("Enter the edges 1/0 format");
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
        printf("v%d\t",i); 
     for(j=1;j<=n;j++)
     {
     
       printf("%d\t",a[i][j]);
     
     }
   }
}
