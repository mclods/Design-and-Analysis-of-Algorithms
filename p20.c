//Improved Bubble Sort
//Bubble Sort
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>
void bubbleSort(int A[],int n)
{
	int i,j,temp,flag;
	for(i=0;i<n;++i)
	{
		flag=0;
		for(j=0;j<n-1-i;++j)
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				flag=1;
			}
			if(flag==0)
				break;
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
	struct timeval t1,t2;
	printf("\nEnter the starting point and ending point:");
	scanf("%d%d",&s,&e);
	
	int *arr=(int *)malloc((e-s+1)*sizeof(int));
	randArr(arr,s,e);
	//printf("\nThe array is:\n");
	//for(i=0;i<(e-s+1);++i)
	//	printf("%d ",arr[i]);
	gettimeofday(&t1,NULL);
	bubbleSort(arr,e-s+1);
	gettimeofday(&t2,NULL);
	//printf("\nThe sorted array is:");
	//for(i=0;i<(e-s+1);++i)
	//	printf("%d ",arr[i]);
	printf("\nTime Taken=%ld MicroSeconds",((t2.tv_sec*pow(10,6)+t2.tv_usec)-(t1.tv_sec*pow(10,6)+t1.tv_usec)));
	return 0;
}