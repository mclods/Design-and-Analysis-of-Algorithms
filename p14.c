//Exponent using recursion
#include<stdio.h>
int power(int x,int y)
{
	if(y==0)
		return 1;
	if(y==1)
		return x;
	return x*power(x,y-1);
}
int main()
{
	int a,b;
	printf("\nEnter the number and its exponent:");
	scanf("%d%d",&a,&b);
	printf("\n%d^%d=%d",a,b,power(a,b));
	return 0;
}
