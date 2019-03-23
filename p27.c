//Activity Selection
#include<stdio.h>
struct act
{
  int actid;
  int start;
  int end;
};
void sort(struct act a[],int n)
{
  int i,j;
  struct act temp;
  for(i=0;i<n;++i)
  {
    for(j=0;j<n-1-i;++j)
    {
      if(a[j].end>a[j+1].end)
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
}
void actSelect(struct act a[],int n)
{
  sort(a,n);
  int i=0,j,sel[n],k=1;
  sel[0]=a[0].actid;
  for(j=1;j<n;++j)
  {
    if(a[i].end<=a[j].start)
    {
      sel[k]=a[j].actid;
      ++k;
      i=j;
    }
  }
  printf("\nActivities Selected:");
  for(i=0;i<k;++i)
  printf("\t%d",sel[i]);
}
void main()
{
  int n,i;
  printf("\nEnter Range:");
  scanf("%d",&n);
  struct act a[n];
  for(i=0;i<n;++i)
  {
    printf("\nEnter Activity Id, StartTime & EndTime:");
    scanf("%d%d%d",&a[i].actid,&a[i].start,&a[i].end);
  }
  actSelect(a,n);
}
