//Q 2. Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix. Display the adjacency matrix.
#include<stdio.h>
int main()
{
  int a[10][10],i,j,n;
  printf("Enter Adjacency matrix vertex");
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
    printf("v%d\t",i);
    for(j=1;j<=n;j++)
    {
       printf("%d\t",a[i][j]);
    }
   
  }
}
