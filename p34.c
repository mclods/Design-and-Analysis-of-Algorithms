//Heap Data Structure(Special)
#include<stdio.h>
void max_heapify(int a[],int i,int e,int diff)
{
	int l,r,temp,largest;
	l=2*i+1-diff;
	r=2*i+2-diff;
	if((a[i]<a[l])&&(l<=e))
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if((a[largest]<a[r])&&(r<=e))
	{
		largest=r;
	}
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		max_heapify(a,largest,e,diff);
	}
}
void build_heap(int a[],int s,int e)
{
	int i;
	for(i=e;i>=s;--i)
	{
		max_heapify(a,i,e,s);
	}
}
void heapSort(int a[],int s,int e)
{
	int i,temp;
	build_heap(a,s,e);
	for(i=e;i>s;--i)
	{
		temp=a[i];
		a[i]=a[s];
		a[s]=temp;
		max_heapify(a,s,i-1,s);
	}
}
int main()
{
	int a[12]={5,3,6,1,2,8,9,10,13,4,12,16};
	heapSort(a,4,9);
	//build_heap(a,0,11);
	for(int i=0;i<12;++i)
		printf("%d ",a[i]);
	return 0;
}
