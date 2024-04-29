//Q 2. Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. Implement function to traverse the graph using Depth First Search (DFS) traversal.
#include<stdio.h>
#define MAX 10
struct stack
{
  int data[MAX];
  int top;
}s;
void init()
{
  s.top==-1;
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
void push(int num)
{
  if(isfull())
    printf("stack is overflow");
  else
    {
       s.top++;
       s.data[s.top]=num;
    }
}
int pop()
{
  int val;
   if(isempty())
     printf("stack is underflow");
  else
    {
      val=s.data[s.top];
      s.top--;
      return val;
    }
}
int a[10][10],visited[10]={0},n;
int dfs(int i) 
{
    int j, tmp;
    visited[i] = 1;
    push(i);
    printf("v%d\t",i);

    while (!isempty()) 
    {
        tmp=pop();

        for (j=1;j<=n;j++) 
        {
            if (a[tmp][j]==1 && visited[j]==0) 
            {
                visited[j]=1;
                push(j);
                printf("v%d\t",j);
            }
        }
    }
}

int main()
{
  int i,j;
  printf("Enter limit:");
  scanf("%d",&n);
  printf("Enter adj graph:");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf("%d",&a[i][j]);
     }
  }   
  dfs(1);    
}
