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
int min_key(struct node a[],int mst[],int n)
{
  int i,min=9999,min_index;
  for(i=0;i<n;++i)
  {
    if((mst[i]!=1)&&(a[i].key<min))
    {
      min=a[i].key;
      min_index=i;
    }
  }
  return min_index;
}
void prim(struct node a[],int mst[],int n)
{
  int u,i;
  a[0].key=0;
  a[0].par=-1;
  for(int c=0;c<n;++c)
  {
    u=min_key(a,mst,n);
    mst[u]=1;
    for(i=0;i<n;++i)
    {
      if((G[u][i]!=0)&&(mst[i]!=1)&&(G[u][i]<a[i].key))
      {
        a[i].key=G[u][i];
        a[i].par=u;
      }
    }
  }
}
int main()
{
  int i,mst[9];
  struct node a[9];
  for(i=0;i<9;++i)
  {
    a[i].key=9999;
    //a[i].par=-1;
    mst[i]=0;
  }
  prim(a,mst,9);
  printf("\nParent\tEdge");
  for(i=1;i<9;++i)
  {
    printf("\n%d\t%d",a[i].par,i);
  }
  return 0;
}
