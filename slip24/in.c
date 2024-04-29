//Q 2. Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. Implement functions to print indegree of all vertices of graph.
#include<stdio.h>
int main()
{
   int i,n,j,a[10][10],in;
   printf("Enter limit:");
   scanf("%d",&n);
   printf("Enter edeg bet 0/1 format:");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
      scanf("%d",&a[i][j]);
      }
   } 
   for(i=1;i<=n;i++)
   {  in=0;
      for(j=1;j<=n;j++)
      {
        in=in+a[j][i];
      }
   } 
   printf("indegree=%d",in);
}
