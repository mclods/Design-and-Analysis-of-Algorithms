//Recursive Binary Search
#include<stdio.h>
int bSearch(int arr[],int s,int e,int item)
{
	if(s>e)
		return -1;
	int mid=(s+e)/2;
	if(item==arr[mid])
		return mid;
	if(item<arr[mid])
		return bSearch(arr,s,mid-1,item);
	if(item>arr[mid])
		return bSearch(arr,mid+1,e,item);
}
int main()
{
	int n,i;
	printf("\nEnter the no. of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of the array:");
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	int item;
	printf("\nEnter element to be searched:");
	scanf("%d",&item);
	int res=bSearch(arr,0,n-1,item);
	if(res==-1)
		printf("\nElement not found");
	else
		printf("\nElement found at index:[%d]",res);
	return 0;
}
