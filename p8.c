//Product of elements using recursion
#include<stdio.h>
int mul(int arr[],int s,int e)
{
	if(s==e)
		return arr[s];
	return arr[s]*mul(arr,s+1,e);
}
int main()
{
	int n,i;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements:\n");
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	printf("\nThe product of all these elements:%d",mul(arr,0,n-1));
	return 0;
}
