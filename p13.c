#include<stdio.h>
int gcd(int x,int y)
{
	int rem=x%y;
	if(rem==0)
		return y;
	return gcd(y,rem);
}
int main()
{
	int a,b;
	printf("\nEnter the two numbers:");
	scanf("%d%d",&a,&b);
	printf("\nThe gcd of these numbers is:%d",gcd(a>b?a:b,a<b?a:b));
	return 0;
}