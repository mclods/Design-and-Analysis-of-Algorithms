//Find square root of a number using Divide and Conquer
#include<stdio.h>
int findSqRoot(int s,int e,int n)
{
	if(s==e)
		return s;
	if(s<e)
	{
	int mid=(s+e)/2;
	int temp=mid*mid;
	if(temp==n)
		return mid;
	else if(temp>n)
		return findSqRoot(s,mid-1,n);
	}
}
int main()
{
	int n;
	printf("\nEnter the number:");
	scanf("%d",&n);
	printf("\nThe floor square root:%d",findSqRoot(1,n,n));
	return 0;
}