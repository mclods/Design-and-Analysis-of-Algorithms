//Decimal to binary using recursion
#include<stdio.h>
int decBin(int n)
{
	if(n==1)
		return 1;
	int bin,rem;
	rem=n%2;
	bin=rem+(10*decBin(n/2));
	return bin;
}
int main()
{
	int n;
	printf("\nEnter the decimal number:");
	scanf("%d",&n);
	printf("\nThe corresponding binary number is:%d",decBin(n));
	return 0;
}
