//Q 2. Write a C program that accepts the vertices and edges of a graph and store it as an adjacencymatrix. Implement function to traverse the graph using Breadth First Search (BFS) traversal.
#include<stdio.h>
#define MAX 10
struct queue
{
  int data[MAX];
  int front,rear;
}q;
void init()
{
  q.front=q.rear=-1;
}
int isempty()
{
   if(q.front==-1 || q.front==q.rear+1)
     return 1;
   else
     return 0;
}
int isfull()
{
  if(q.rear==MAX-1)
   return 1;
  else
   return 0;
}
void addq(int num)
{
  if(!isfull())
  {
   if(q.front==-1)
    q.front=0;
    q.rear++;
    q.data[q.rear]=num;
   }
}
int delq()
{
   int val;
     val=q.data[q.front];
     q.front++;
     return val;

}
void bfs(int a[10][10],int n)
{
   int i,j;
   int visited[10]={0};
   printf("\nbfs:");
   init();
   i=1;
   visited[i]=1;
   addq(i);
   while(!isempty())
   {
     i=delq();
     printf("\t%d",i);
     for(j=1;j<=n;j++)
     {
       if(a[i][j]==1 && visited[j]==0)
       {
         addq(j);
         visited[j]=1;
       }
     }
   }
}
int main()
{
  int i,j,n,a[10][10];
  printf("Enter limit:");
  scanf("%d",&n);
  printf("Enter adj matrix:");
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&a[i][j]);
     }
  }
  bfs(a,n);
}
