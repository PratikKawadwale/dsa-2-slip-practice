//Q 2. Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. Implement functions to print indegree, outdegree and total degree of all vertices of graph.
#include<stdio.h>
int main()
{
 int i,j,a[10][10],n,in,out,total; 
 printf("Enter limit:");
 scanf("%d",&n);
 printf("Enter adj edge bet 0/1 formate:");
 for(i=1;i<=n;i++)
 {
   for(j=1;j<=n;j++)
   {
     scanf("%d",&a[i][j]);
    }
 }
  for(i=1;i<=n;i++)
 {  
   printf("\nv%d\t",i);
   for(j=1;j<=n;j++)
   {
     printf("%d\t",a[i][j]);
    }
 }
 for(i=1;i<=n;i++)
 {
   in=0;
   out=0;
   for(j=1;j<=n;j++)
   {
     in=in+a[j][i];
     out=out+a[i][j];
    }
 }
 printf("\nindegree:%d\noutdegree:%d\ntotaldegree:%d",in,out,in+out);

}
