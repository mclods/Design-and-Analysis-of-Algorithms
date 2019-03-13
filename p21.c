//Merge Sort
#include<stdio.h>
#include<stdlib.h>
void merge(int A[],int s,int m,int e)
{
	int i=s,j=m+1,k=0;
	int *temp=(int *)malloc((e-s+1)*sizeof(int));
	while(i<=m&&j<=e)
	{
		if(A[i]<A[j])
		{
			temp[k]=A[i];
			++i;
		}
		else
		{
			temp[k]=A[j];
			++j;
		}
		++k;
	}
	while(i<=m)
	{
		temp[k]=A[i];
		++i;
		++k;
	}
	while(j<=e)
	{
		temp[k]=A[j];
		++j;
		++k;
	}
	for(i=0;i<(e-s+1);++i)
	{
		A[s+i]=temp[i];
	}
}
void mergeSort(int A[],int s,int e)
{
	if(s<e)
	{
		int mid=(s+e)/2;
		mergeSort(A,s,mid);
		mergeSort(A,mid+1,e);
		merge(A,s,mid,e);
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
	int s,e,i;
	printf("\nEnter the starting point:");
	scanf("%d",&s);
	printf("\nEnter the ending point:");
	scanf("%d",&e);
	int *arr=(int *)malloc((e-s+1)*sizeof(int));
	randArr(arr,s,e);
	printf("\nThe array is:\n");
	for(i=0;i<(e-s+1);++i)
		printf("%d ",arr[i]);
	mergeSort(arr,0,e-s);
	printf("\nThe sorted array is:");
	for(i=0;i<(e-s+1);++i)
		printf("%d ",arr[i]);
	return 0;
}