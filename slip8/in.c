//Q 2. Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. Implement functions to print indegree of all vertices of graph
#include<stdio.h>
int main()
{
  int i,j,n,in,a[10][10];
  printf("Enter the adjcency matrix limit:");
  scanf("%d",&n);
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
    printf("%d",i,j);
    for(j=1;j<=n;j++)
    {
      printf("\t%d",a[i][j]);
    }
  }
  for(i=1;i<=n;i++)
  { 
    in=0;
    for(j=1;j<=n;j++)
    {
      in=in+a[j][i];
    }
  }
  printf("\nindegree:%d",in);
}
