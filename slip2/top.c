//Q 2. Write a C program for the implementation of Topological sorting
#include<stdio.h>
#include<stdlib.h>
#define MAX 30
struct stack
{
  int data[MAX];
  int top;
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
void push(int num)
{
  if(!isfull())
  {
    s.top++;
    s.data[s.top]=num;
  }
}
int pop()
{
  int val;
  if(!isempty())
  {
     val=s.data[s.top];
     s.top--;
    return val;
  }
}
void top(int a[10][10],int n)
{
  int visited[10]={0},in[10]={0};
  int i,j,k;
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
       in[i]=in[i]+a[j][i];
     }
  }
  while(1)
  {
    for(i=1;i<=n;i++)
    {
      if(in[i]==0 && visited[i]==0)
     
        push(i);
        visited[i]=1;
        printf("v%d\t",i);
    
    }
    k=pop();
    for(j=1;j<=n;j++)
    {
      if(a[k][j]==1)
       in[j]=in[j]-1;
    }
    if(isempty())
    {
      break;
    }
  }
}
int main()
{
  int a[10][10],i,n,j;
  init();
  printf("Enter limit:");
  scanf("%d",&n);
  printf("Enter matrix:");
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&a[i][j]);
     }
  }
  top(a,n);
}
