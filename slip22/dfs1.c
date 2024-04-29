//Q 2. Write a C program that accepts the vertices and edges of a graph and store it as an adjacencymatrix. Implement function to traverse the graph using Depth First Search (DFS) traversal.
#include<stdio.h>
#define MAX 10
struct stack
{
  int data[MAX],top;
}s;
void init()
{
  s.top=-1;
}
int isempty()
{
  if(s.top==-1)
    return 1;
  else
    return 0;
}
int isfull()
{
  if(s.top==MAX-1)
    return 1;
  else
    return 0;
}
void push( int num)
{
  if(isfull())
    printf("stack is overflow");
  else
    {
      s.data[++s.top]=num;
    }
}
int pop()
{
  if(isempty())
    printf("stack is underflow");
  else
   {
     return(s.data[s.top--]);
   }
}
int a[10][10],visited[10]={0},n;
int dfs(int i)
{
  int j,temp;
  init();
  push(i);
  visited[i]=1;
  printf("v%d\t",i);
  while(!isempty())
  {
    temp=pop();
    for(j=1;j<=n;j++)
    {
      if(a[temp][j]==1 && visited[j]==0)
      {
        push(j);
        visited[j]=1;
        printf("v%d\t",j);
      }
    }
  }
}
int main()
{
  int i,j;
  printf("enter limit:");
  scanf("%d",&n);
  printf("enter graph:\n");
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
        scanf("%d",&a[i][j]);
     }
  }
  dfs(1);
}
