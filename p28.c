//Optimal Storage on Tapes
#include<stdio.h>
void sort(int a[],int n)
{
  int i,j,temp;
  for(i=0;i<n;++i)
  {
    for(j=0;j<n-1-i;++j)
    {
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
}
float optStr(int a[],int n)
{
  sort(a,n);
  int i,j,sum;
  float mrt=0;
  printf("\nOptimal Order:");
  for(i=0;i<n;++i)
  printf("\t%d",a[i]);
  for(i=0;i<n;++i)
  {
    sum=0;
    for(j=0;j<=i;++j)
    {
      sum+=a[j];
    }
    mrt+=sum;
  }
  mrt/=n;
  return mrt;
}
int main()
{
  int n,i;
  printf("\nEnter Range:");
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;++i)
  {
    printf("\nEnter size of file %d:",i+1);
    scanf("%d",&a[i]);
  }
  printf("\nMinimum Retrieval Time:%f",optStr(a,n));
  return 0;
}
