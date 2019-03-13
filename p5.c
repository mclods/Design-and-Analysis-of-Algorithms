#include<stdio.h>
int sum(int n)
{
	if(n==0)
		return 0;
	return n+sum(n-1);
}
int main()
{
	int n;
	printf("\nEnter the value of n:");
	scanf("%d",&n);
	printf("\nThe sum of %d numbers is:%d",n,sum(n));
	return 0;
}