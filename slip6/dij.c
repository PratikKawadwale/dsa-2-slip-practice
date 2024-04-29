//Q 1. Write a C program for the implementation of Dijkstra’s shortest path algorithm for findingshortest path from a given source vertex using adjacency cost matrix.
#include<stdio.h>
#include<limits.h>

int n,i,u,v,a[10][10],max,j;
int mindistance(int dist[],int visited[])
{
  int min=999,index,i;
  for(i=0;i<n;i++)
  {
    if(visited[i]==0 && dist[i]<=min)
    {
      min=dist[i];
      index=i;
    }
  }
  return index;
}
void display(int dist[])
{
  
  printf("vertex distance for source\n");
  for(i=0;i<n;i++)
  printf("%d-->%d\n",i,dist[i]);
}
void dijkstra(int a[10][10],int src)
{
  
  int dist[10];
  int visited[10];
  for(i=0;i<n;i++)
  {
    dist[i]=999;
    visited[i]=0;
  }
  dist[src]=0;
  for(i=0;i<n-1;i++)
  {
    u=mindistance(dist,visited);
    visited[u]=1;
    for(v=0;v<n;v++)
    {
       if(!visited[v] && a[u][v] && dist[u] !=999 && dist[u] + a[u][v] <dist[v])
       {
         dist[v]=dist[u]+a[u][v];
       }
    }
  }
  display(dist);
}
int main()
{
  printf("Enter no of vertex:");
  scanf("%d",&n);
  printf("Enter cost matrix:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
      if(a[i][j]==0)
      a[i][j]=999;
    }
  }
  max=n;
  dijkstra(a,0);
}
