#include<stdio.h>
int fibPrint(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return(fibPrint(n-1)+fibPrint(n-2));
}
int main()
{
	int i,n;
	printf("\nEnter the no. of terms:");
	scanf("%d",&n);
	printf("\nThe fibonacci series is:\n");
	for(i=0;i<=n;++i)
		printf("%d ",fibPrint(i));
	return 0;
}