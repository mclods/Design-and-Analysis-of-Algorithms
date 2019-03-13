//Bubble Sort
#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int A[],int n)
{
	int i,j,temp;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n-1-i;++j)
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
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
	bubbleSort(arr,e-s+1);
	printf("\nThe sorted array is:");
	for(i=0;i<(e-s+1);++i)
		printf("%d ",arr[i]);
	return 0;
}