//Dynamically allocating 2D arrays
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n,i,j;
	printf("\nEnter the no. of rows:");
	scanf("%d",&m);
	printf("\nEnter the no. of columns:");
	scanf("%d",&n);
	//By Using a Single Pointer
	/*int *arr1;
	arr1=(int *)malloc(m*n*sizeof(int));
	printf("\nEnter the elements of the array:");
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",arr1+i*m+j);
		}
	}
	printf("\nThe 2D array is:\n");
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			printf("%d ",*(arr1+i*m+j));
		}
		printf("\n");
	}*/
	//By Using a Double Pointer
	/*int **arr1;
	arr1=(int **)malloc(m*sizeof(int *));
	for(i=0;i<n;++i)
		arr1[i]=(int *)malloc(n*sizeof(int));
	printf("\nEnter the elements of the array:");
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",(*(arr1+i)+j));
		}
	}
	printf("\nThe 2D array is:\n");
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			printf("%d ",*(*(arr1+i)+j));
		}
		printf("\n");
	}*/
	int *arr1[m];
	for(i=0;i<m;++i)
		arr1[i]=(int *)malloc(sizeof(int));
	printf("\nEnter the elements of the array:");
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",(arr1[i]+j));
		}
	}
	printf("\nThe 2D array is:\n");
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			printf("%d ",*(arr1[i]+j));
		}
		printf("\n");
	}
	return 0;
}