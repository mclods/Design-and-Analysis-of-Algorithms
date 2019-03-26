//Kruskal's Algorithm
#include<stdio.h>
int G[9][9]={{0,4,0,0,0,0,0,8,0},
             {4,0,8,0,0,0,0,11,0},
             {0,8,0,7,0,4,0,0,2},
             {0,0,7,0,9,14,0,0,0},
             {0,0,0,9,0,10,0,0,0},
             {0,0,4,14,10,0,2,0,0},
             {0,0,0,0,0,2,0,1,6},
             {8,11,0,0,0,0,1,0,7},
             {0,0,2,0,0,0,6,7,0}};
struct node{
  int s;
  int d;
  int wt;
  int sel;
};
int find(int par[],int i)
{
  if(par[i]==-1)
  {
    return i;
  }
  return find(par,par[i]);
}
void union1(int par[],int i,int j)
{
  int xset=find(par,i);
  int yset=find(par,j);
  par[xset]=yset;
}
void sort(struct node a[],int n)
{
  int i,j;
  struct node temp;
  for(i=0;i<n;++i)
  {
    for(j=0;j<n-1-i;++j)
    {
      if(a[j].wt>a[j+1].wt)
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
}
void kruskal(struct node a[],int par[],int k)
{
  int i,j,l=0;
  for(i=0;(i<k&&l<9);++i)
  {
    if(find(par,a[i].s)!=find(par,a[i].d))
    {
      a[i].sel=1;
      ++l;
      union1(par,a[i].s,a[i].d);
    }
  }
  printf("\nEdges Selected:\n");
    for(i=0;i<k;++i)
    {
      if(a[i].sel!=0)
      {
        printf("\n(%d,%d)",a[i].s,a[i].d);
      }
    }
}
int main()
{
  int i,j,k=0,par[9];
  struct node a[50];
  for(i=0;i<9;++i)
  {
    for(j=i+1;j<9;++j)
    {
      if(G[i][j]!=0)
      {
        a[k].s=i;
        a[k].d=j;
        a[k].wt=G[i][j];
        a[k].sel=0;
        ++k;
      }
    }
  }
  for(i=0;i<9;++i)
    par[i]=-1;
  sort(a,k);
  kruskal(a,par,k);
  return 0;
}
