//Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix. Display the adjacency matrix.
#include<stdio.h>
int main()
{
  int a[10][10],i,j,n;
  printf("Enter adjacency matrix limit");
  scanf("%d",&n);
  printf("Enter graph  in matrix 0&1 format");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("Enter edge betn v%d and v%d(0/1)",i,j);
      scanf("%d",&a[i][j]);
    }
  }
  printf("display adjacency matrix");
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
