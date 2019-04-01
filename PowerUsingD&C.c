#include<stdio.h>
int POWER(int x,int n)
{
  if(n==0)
    return 1;
  else if(n==1)
    return x;
  else if(n%2==0)
    return POWER(x*x,n/2);
  else
    return POWER(x*x,n/2)*x;
}
