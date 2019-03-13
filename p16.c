//Reverse a number using recursion
#include<stdio.h>
int numRev(int o)
{
	int rem,new;
	rem=o%10;
	if(rem==o)
		return o;
	new=rem+10*numRev(o/10);
	return (rem+(10*new));

}
int main()
{
	int n;
	printf("\nEnter the number:");
	scanf("%d",&n);
	printf("\nReversed number:%d",numRev(n));
	return 0;
}
