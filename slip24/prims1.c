//Q 1. Write a C program for the Implementation of Prim’s Minimum spanning tree algorithm.
#include<stdio.h>
int i,j,a,b,u,v,e=1,n;
int visited[10]={0},min,mincost=0,c[10][10];
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
  printf("Display matrix:");
  for(i=1;i<=n;i++)
  { 
     printf("\n");
     for(j=1;j<=n;j++)
     {
        printf("%d",c[i][j]);
     }
  }
  visited[1]=1;
  printf("\n");
  for(e=1;e<=n;e++)
  {
     for(i=1,min=999;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         if(c[i][j]<min && visited[j]==0)
         {
            min=c[i][j];
            a=u=i;
            b=v=j;
         }
     }
  }
  if(visited[u]==0 || visited[v]==0)
  {
    printf("\nedge%d:(%d->%d)min:%d",e,a,b,min);
    mincost=mincost+min;
    visited[v]=1;
  }
  c[a][b]=c[b][a]=999;
  }
  printf("\n mincost=%d",mincost);
}
