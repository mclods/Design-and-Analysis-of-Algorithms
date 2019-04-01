#include<stdio.h>
void minmax(int arr[],int s,int e,int *min,int *max)
{
  if(e-s>=1)
  {
    *min=arr[s]<arr[e]?arr[s]:arr[e];
    *max=arr[s]>arr[e]?arr[s]:arr[e];
    return;
  }
  else
  {
    int m=(s+e)/2,min1,max1,min2,max2;
    minmax(arr,s,m,&min1,&max1);
    minmax(arr,m+1,e,&min2,&max2);
    *min=min1<min2?min1:min2;
    *max=max1>max2?max1:max2;
  }
}
int main()
{
  int a[7]={1,2,3,4,5,6,7};
  int min,max;
  min=a[0];
  max=a[0];
  minmax(a,0,6,&min,&max);
  printf("\nMin:%d Max:%d",min,max);
  return 0;
}
