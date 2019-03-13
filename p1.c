//Generating Random Array and Multiplying all the elements
#include<stdio.h>
#include<stdlib.h>
int mul(int arr[],int l)
{
	int i,p=1;
	for(i=0;i<l;++i)
		p*=arr[i];
	return p;
}
void randInt(int arr[],int l)
{
	int i;
	for(i=0;i<l;++i)
	{
		arr[i]=(random()%l);
	}
}
int main()
{
	int i,s,e;
	printf("\nEnter the starting point:");
	scanf("%d",&s);
	printf("\nEnter ending point:");
	scanf("%d",&e);
	int arr[e-s+1];
	randInt(arr,e-s+1);
	printf("\nYour random array is:\n");
	for(i=0;i<(e-s+1);++i)
		printf("%d ",arr[i]);
	printf("\nProduct of all elements of the array:%d",mul(arr,e-s+1));
	return 0;
}
