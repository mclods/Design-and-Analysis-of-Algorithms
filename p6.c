//Largest element of array using recursion
#include<stdio.h>
int largeArr(int arr[],int s,int e)
{
	if(s==e)
		return arr[s];
	int big=arr[s];
	if(big<largeArr(arr,s+1,e))
		big=largeArr(arr,s+1,e);
	return big;
}
int main()
{
	int n,i;
	printf("\nEnter the size of the array:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of the array:\n");
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	printf("\nThe biggest element in the array is:%d",largeArr(arr,0,n-1));
	return 0;
}
