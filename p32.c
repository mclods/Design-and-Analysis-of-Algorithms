//Prim's Algorithm
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
  int key;
  int par;
};
int minIndex(struct node a[],int n)
{
  int i,min=0;
  for(i=1;i<n;++i)
  {
    if(a[i].key<a[min].key)
    {
      min=i;
    }
  }
  return min;
}
int main()
{
  int i,mst[9],u,count=0;
  struct node a[9];
  for(i=0;i<9;++i)
  {
    a[i].key=9999;
    a[i].par=-1;
    mst[i]=0;
  }
  a[0].key=0;
  while(count<9)
  {
    u=minIndex(a,9);
    mst[u]=1;
    ++count;
    for(i=0;i<9;++i)
    {
      if((G[u][i]!=0)&&(mst[i]!=1)&&(G[u][i]<a[i].key))
      {
        a[i].par=u;
        a[i].key=G[u][i];
      }
    }
  }
  printf("\nEdges Included:\n");
  for(i=0;i<9;++i)
  {
    printf("\n(%d,%d)",a[i].par,i);
  }
  return 0;
}
