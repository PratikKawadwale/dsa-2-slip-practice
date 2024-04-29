//prims algorithm
#include<stdio.h>
#include<stdlib.h>
int n,a,b,u,v,i,j,e=1;
int visited[10]={0},min,mincost=0,c[10][10];
void main()
{
  printf("Enter the number of vertices=");
  scanf("%d",&n);
  printf("Enter adjacency matrix=\n");
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&c[i][j]);
       if(c[i][j]==0)
       c[i][j]=999;
     }
  }
  visited[1]=1;
  printf("\n");
  for(e=1;e<=n;e++)
  {
    for(i=1,min=999;i<=n;i++)
      for(j=1;j<=n;j++)
      if(c[i][j]<min && visited[j]==0)
      {
         min=c[i][j];
         a=u=i;
         b=v=j;
      }
      if(visited[u]==0 || visited[v]==0)
      {
        printf("\n edge%d:(%d->%d) cost:%d",e,a,b,min);
        mincost=mincost+min;
        visited[b]=1;
      }
      c[a][b]=c[b][a]=999;
  }
  printf("\n minimum cost=%d",mincost);
}
