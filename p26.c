//Job Sequencing with Deadlines
#include<stdio.h>
struct jb
{
  int jid;
  int profit;
  int deadl;
};
int min(int a,int b)
{
  return a<b?a:b;
}
void sort(struct jb a[],int n)
{
  int i,j;
  struct jb temp;
  for(i=0;i<n;++i)
  {
    for(j=0;j<n-1-i;++j)
    {
      if(a[j].profit<a[j+1].profit)
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
}
int jobSeq(struct jb a[],int n)
{
  int tprofit=0;
  sort(a,n);
  int result[n],slot[n],i,j;
  for(i=0;i<n;++i)
    {
      slot[i]=0;
      result[i]=-1;
    }
    for(i=0;i<n;++i)
    {
      for(j=(min(n,a[i].deadl)-1);j>=0;--j)
      {
        if(slot[j]==0)
        {
          slot[j]=a[i].jid;
          result[j]=i;
          break;
        }
      }
    }
    for(i=0;i<n;++i)
    {
      //if(result[i]!=-1)
      if(slot[i]!=0)
        tprofit+=a[slot[i]-1].profit;
    }
    return tprofit;
}
int main()
{
  int n,i;
  printf("\nEnter the range:");
  scanf("%d",&n);
  struct jb a[n];
  for(i=0;i<n;++i)
  {
    printf("\nEnter JobID, Profit and Deadline:");
    scanf("%d%d%d",&a[i].jid,&a[i].profit,&a[i].deadl);
  }
  printf("\nMaximum Profit:%d",jobSeq(a,n));
  return 0;
}
