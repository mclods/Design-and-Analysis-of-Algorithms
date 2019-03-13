#include<stdio.h>
int fact(int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 1;
	return n*fact(n-1);
}
int main()
{
	int n;
	printf("\nEnter the number:");
	scanf("%d",&n);
	printf("\nThe factorial of the number is:%d",fact(n));
	return 0;
}