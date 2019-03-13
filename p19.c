//Insertion Sort
#include<stdio.h>
#include<stdlib.h>
void insSort(int A[],int n)
{
	int i,hole,value;
	for(i=1;i<n;++i)
	{
		value=A[i];
		hole=i;
		while(hole>0&&A[hole-1]>value)
		{
			A[hole]=A[hole-1];
			--hole;	
		}
		A[hole]=value;
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
	insSort(arr,e-s+1);
	printf("\nThe sorted array is:");
	for(i=0;i<(e-s+1);++i)
		printf("%d ",arr[i]);
	return 0;
}