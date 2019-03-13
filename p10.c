#include<stdio.h>
#include<string.h>
void strRev(char arr[],int s,int e)
{
  if(s==e)
  {
    return;
  }
  char temp;
  temp=arr[s];
  arr[s]=arr[e];
  arr[e]=temp;
  strRev(arr,s+1,e-1);
}
int main()
{
  char str[10];
  printf("\nEnter the string:");
  scanf("%s",str);
  strRev(str,0,strlen(str)-1);
  printf("\nThe reversed string:%s",str);
  return 0;
}
