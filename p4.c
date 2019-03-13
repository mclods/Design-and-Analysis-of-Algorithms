//Insertion Sort time calculated
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void randInt(int arr[],int s,int e)
{
	int i;
	for(i=0;i<(e-s+1);++i)
	{
		arr[i]=(random()%(e-s+1));
	}
}
void insertionSort(int arr[],int l)
{
	int i,value,hole;
	for(i=1;i<l;++i)
	{
		value=arr[i];
		hole=i;
		while((hole>0)&&(arr[hole-1]>value))
		{
			arr[hole]=arr[hole-1];
			--hole;
		}
		arr[hole]=value;
	}
}
int main()
{
	int s,e,i,j;
	struct timeval t1,t2;
	printf("\nEnter the starting point:");
	scanf("%d",&s);
	printf("\nEnter the ending point:");
	scanf("%d",&e);
	int arr[e-s+1];
	randInt(arr,s,e);
	printf("\nThe array is:\n");
	for(i=0;i<(e-s+1);++i)
		printf("%d ",arr[i]);
	gettimeofday(&t1,NULL);
	insertionSort(arr,e-s+1);
	gettimeofday(&t2,NULL);
	printf("\nTime taken:%ldSeconds %ldMicroSeconds",t2.tv_sec-t1.tv_sec,t2.tv_usec-t1.tv_usec);
	return 0;
}
