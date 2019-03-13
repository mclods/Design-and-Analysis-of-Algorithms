//Using gettimeofday
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int mul(int *arr,int m,int n)
{
	int i,j,p=1;
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			p*=*(arr+i*m+j);
		}
	}
	return p;
}
void randInt(int *arr,int m,int n,int s,int e)
{
	int i,j;
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			*(arr+i*m+j)=(random()%(e-s+1));
		}
	}
}
int main()
{
	int i,j,m,n,e,s;
	struct timeval t1,t2;
	printf("\nEnter the no. of rows of the array:");
	scanf("%d",&m);
	printf("\nEnter the no. of columns of the array:");
	scanf("%d",&n);
	printf("\nEnter the starting point:");
	scanf("%d",&s);
	printf("\nEnter the ending point:");
	scanf("%d",&e);
	int *arr=(int *)malloc(sizeof(int));
	randInt(arr,m,n,s,e);
	printf("\nYour array is:\n");
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			printf("%d ",*(arr+i*m+j));
		}
		printf("\n");
	}
	gettimeofday(&t1,NULL);
	printf("\nThe product of all elements of the array:%d",mul(arr,m,n));
	gettimeofday(&t2,NULL);
	printf("\nTime Taken:%ldSeconds %ldMicroSeconds",t2.tv_sec-t1.tv_sec,t2.tv_usec-t1.tv_usec);
	return 0;
}
