//Q 1. Write a C program for the Implementation of Kruskal’s Minimum spanning tree algorithm
#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,c[10][10],parent[10];
int find(int);
int union_sets(int,int);
int main()
{
  printf("Enter no of vertex:");
  scanf("%d",&n);
  printf("Enter cost matrix:");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf("%d",&c[i][j]);
      if(c[i][j]==0)
      c[i][j]=999;
    }
  }
  printf("Minimum spaning tree:\n");
  while(ne<n)
  {
    for(i=1,min=999;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
         if(c[i][j]<min)
         {
           min=c[i][j];
           a=u=i;
           b=v=j;
         }         
       }
    }
    u=find(u);
    v=find(v);
    if(union_sets(u,v))
    {
      printf("%d edge(%d,%d)=%d\n",ne++,a,b,min);
      mincost=mincost+min;
    }
    c[a][b]=c[b][a]=999;
  }
  printf("Minimum cost=%d\n",mincost);
}
int find(int i)
{
  while(parent [i])
   i=parent[i];
   return i;
}
int union_sets(int i,int j)
{
  if(i!=j)
  {
    parent[j]=i;
    return 1;
  }
  return 0;
}
