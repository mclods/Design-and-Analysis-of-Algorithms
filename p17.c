//Introduction to Sorting
//Selection Sort
#include<stdio.h>
#include<stdlib.h>
void selSort(int A[],int n)
{
	int i,j,temp,iMin;
	for(i=0;i<n-1;++i)
	{
		iMin=i;
		for(j=i+1;j<n;++j)
		{
			if(A[j]<A[iMin])
			{
				iMin=j;
			}
		}
		temp=A[i];
			A[i]=A[iMin];
			A[iMin]=temp;
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
	selSort(arr,e-s+1);
	printf("\nThe sorted array is:");
	for(i=0;i<(e-s+1);++i)
		printf("%d ",arr[i]);
	return 0;
}