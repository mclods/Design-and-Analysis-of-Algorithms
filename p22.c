//Quick Sort
#include<stdio.h>
#include<stdlib.h>
int partition(int A[],int s,int e)
{
	int l=s,u=e,pivot=A[s],temp;
	while(1)
	{
		while(A[l]<=pivot&&l<e)
		{
			++l;
		}
		while(A[u]>pivot)
		{
			--u;
		}
		if(l<u)
		{
			temp=A[l];
			A[l]=A[u];
			A[u]=temp;
		}
		else
		{
			temp=A[u];
			A[u]=A[s];
			A[s]=temp;
			return u;
		}
	}
}
void quickSort(int A[],int s,int e)
{
	if(s<e)
	{
		int pIndex=partition(A,s,e);
		//quickSort(A,s,pIndex-1);
		//quickSort(A,pIndex+1,e);
	}
}
void randArr(int A[],int s,int e)
{
	int i;
	for(i=0;i<(e-s+1);++i)
	{
		A[i]=s+(random()%(e-s+1));
	}
}
int main()
{
	int s=0,e=7,i;
	printf("\nEnter the starting point:");
	scanf("%d",&s);
	printf("\nEnter the ending point:");
	scanf("%d",&e);
	int *arr=(int *)malloc((e-s+1)*sizeof(int));
	randArr(arr,s,e);
	printf("\nThe array is:\n");
	for(i=0;i<(e-s+1);++i)
		printf("%d ",arr[i]);
	quickSort(arr,0,e-s);
	printf("\nThe sorted array is:");
	for(i=0;i<(e-s+1);++i)
		printf("%d ",arr[i]);
	return 0;
}
