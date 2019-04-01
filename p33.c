//Sorting
//Selection Sort
//Bubble Sort
//Improved Bubble Sort
//Insertion Sort
//Merge Sort
//Quick Sort
//Randomized Quick Sort
//Heap Sort
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>
void randArr(int a[],int s,int e)
{
	int i;
	for(i=0;i<(e-s+1);++i)
	{
		a[i]=s+(rand()%(e-s+1));
	}
	printf("\nYour Random Array:");
	for(i=0;i<(e-s+1);++i)
	{
		printf("%d ",a[i]);
	}
}
void selectionSort(int a[],int s,int e)
{
	int i,j,iMin,temp;
	for(i=0;i<(e-s);++i)
	{
		iMin=i;
		for(j=i+1;j<(e-s+1);++j)
		{
			if(a[j]<a[iMin])
				iMin=j;
		}
		temp=a[i];
		a[i]=a[iMin];
		a[iMin]=temp;
	}
}
void bubbleSort(int a[],int s,int e)
{
	int i,j,temp;
	for(i=0;i<(e-s);++i)
	{
		for(j=0;j<(e-s-i);++j)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void impbubbleSort(int a[],int s,int e)
{
	int i,j,temp,flag;
	for(i=0;i<(e-s);++i)
	{
		flag=0;
		for(j=0;j<(e-s-i);++j)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
}
void insertionSort(int a[],int s,int e)
{
	int i,value,hole;
	for(i=1;i<(e-s+1);++i)
	{
		value=a[i];
		hole=i;
		while((hole>0)&&(a[hole-1]>value))
		{
			a[hole]=a[hole-1];
			--hole;
		}
		a[hole]=value;
	}
}
void merge(int a[],int s,int mid,int e)
{
	int i=s,j=mid+1,k=0;
	int *b=(int *)malloc((e-s+1)*sizeof(int));
	while((i<=mid)&&(j<=e))
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			++i;
			++k;
		}
		else
		{
			b[k]=a[j];
			++j;
			++k;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		++i;
		++k;
	}
	while(j<=e)
	{
		b[k]=a[j];
		++j;
		++k;
	}
	for(i=0;i<(e-s+1);++i)
	{
		a[s+i]=b[i];
	}
	free(b);
}
void mergeSort(int a[],int s,int e)
{
	int mid;
	if(s<e)
	{
		mid=(s+e)/2;
		mergeSort(a,s,mid);
		mergeSort(a,mid+1,e);
		merge(a,s,mid,e);
	}
}
int partition(int a[],int s,int e)
{
	int l=s,u=e,piv,temp;
	piv=a[s];
	while(1)
	{
		while((a[l]<=piv)&&(l<e))
		{
			++l;
		}
		while(a[u]>piv)
		{
			--u;
		}
		if(l<u)
		{
			temp=a[l];
			a[l]=a[u];
			a[u]=temp;
		}
		else
		{
			temp=a[u];
			a[u]=a[s];
			a[s]=temp;
			return u;
		}
	}
}
void quickSort(int a[],int s,int e)
{
	int pIndex;
	if(s<e)
	{
		pIndex=partition(a,s,e);
		quickSort(a,s,pIndex-1);
		quickSort(a,pIndex+1,e);
	}
}
int partitionR(int a[],int s,int e)
{
	int l=s,u=e,piv,temp,index;
	index=s+(rand()%(e-s+1));
	temp=a[s];
	a[s]=a[index];
	a[index]=temp;
	piv=a[s];
	while(1)
	{
		while((a[l]<=piv)&&(l<e))
		{
			++l;
		}
		while(a[u]>piv)
		{
			--u;
		}
		if(l<u)
		{
			temp=a[l];
			a[l]=a[u];
			a[u]=temp;
		}
		else
		{
			temp=a[u];
			a[u]=a[s];
			a[s]=temp;
			return u;
		}
	}
}
void randomizedquickSort(int a[],int s,int e)
{
	int pIndex;
	if(s<e)
	{
		pIndex=partitionR(a,s,e);
		quickSort(a,s,pIndex-1);
		quickSort(a,pIndex+1,e);
	}
}
void max_heapify(int a[],int i,int e)
{
	int l,r,temp,largest;
	l=2*i+1;
	r=2*i+2;
	if((a[i]<a[l])&&(l<e))
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if((a[largest]<a[r])&&(r<e))
	{
		largest=r;
	}
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		max_heapify(a,largest,e);
	}
}
void build_heap(int a[],int s,int e)
{
	int i;
	for(i=(e-1)/2;i>=s;--i)
	{
		max_heapify(a,i,e);
	}
}
void heapSort(int a[],int s,int e)	//Don't Use
{
	int i,temp;
	build_heap(a,s,e);
	for(i=e;i>s;--i)
	{
		temp=a[s];
		a[s]=a[i];
		a[i]=temp;
		max_heapify(a,s,i);
	}
}
int main()
{
	int i,s,e;
	struct timeval t1,t2;
	printf("\nEnter the starting and ending point:");
	scanf("%d%d",&s,&e);
	int a[e-s+1];
	/*randArr(a,s,e);
	gettimeofday(&t1,NULL);
	selectionSort(a,0,e-s);
	gettimeofday(&t2,NULL);
	printf("\nTime Taken by Selection Sort:%ld s",((t2.tv_sec)-(t1.tv_sec)));
	printf("\nAfter Sorting using Selection Sort:");
	for(i=0;i<(e-s+1);++i)
	{
		printf("%d ",a[i]);
	}*/
	/*randArr(a,s,e);
	gettimeofday(&t1,NULL);
	bubbleSort(a,0,e-s);
	gettimeofday(&t2,NULL);
	printf("\nTime Taken by Bubble Sort:%ld s",((t2.tv_sec)-(t1.tv_sec)));
	printf("\nAfter Sorting using Bubble Sort:");
	for(i=0;i<(e-s+1);++i)
	{
		printf("%d ",a[i]);
	}*/
	/*randArr(a,s,e);
	gettimeofday(&t1,NULL);
	impbubbleSort(a,0,e-s);
	gettimeofday(&t2,NULL);
	printf("\nTime Taken by Improved Bubble Sort:%ld s",((t2.tv_sec)-(t1.tv_sec)));
	printf("\nAfter Sorting using Improved Bubble Sort:");
	for(i=0;i<(e-s+1);++i)
	{
		printf("%d ",a[i]);
	}*/
	/*randArr(a,s,e);
	gettimeofday(&t1,NULL);
	insertionSort(a,0,e-s);
	gettimeofday(&t2,NULL);
	printf("\nTime Taken by Insertion Sort:%ld s",((t2.tv_sec)-(t1.tv_sec)));
	printf("\nAfter Sorting using Insertion Sort:");
	for(i=0;i<(e-s+1);++i)
	{
		printf("%d ",a[i]);
	}*/
	/*randArr(a,s,e);
	gettimeofday(&t1,NULL);
	mergeSort(a,0,e-s);
	gettimeofday(&t2,NULL);
	printf("\nTime Taken by Merge Sort:%ld ms",((t2.tv_usec)-(t1.tv_usec)));
	/*printf("\nAfter Sorting using Merge Sort:");
	for(i=0;i<(e-s+1);++i)
	{
		printf("%d ",a[i]);
	}*/
	//randArr(a,s,e);
	/*gettimeofday(&t1,NULL);
	quickSort(a,0,e-s);
	gettimeofday(&t2,NULL);
	printf("\nTime Taken by Quick Sort:%ld ms",((t2.tv_usec)-(t1.tv_usec)));
	/*printf("\nAfter Sorting using Quick Sort:");
	for(i=0;i<(e-s+1);++i)
	{
		printf("%d ",a[i]);
	}*/
	//randArr(a,s,e);
	/*gettimeofday(&t1,NULL);
	randomizedquickSort(a,0,e-s);
	gettimeofday(&t2,NULL);
	printf("\nTime Taken by Randomized Quick Sort:%ld ms",((t2.tv_usec)-(t1.tv_usec)));
	/*printf("\nAfter Sorting using Randomized Quick Sort:");
	for(i=0;i<(e-s+1);++i)
	{
		printf("%d ",a[i]);
	}*/
	randArr(a,s,e);
	gettimeofday(&t1,NULL);
	heapSort(a,0,e-s);
	gettimeofday(&t2,NULL);
	printf("\nTime Taken by Heap Sort:%ld ms",((t2.tv_usec)-(t1.tv_usec)));
	printf("\nAfter Sorting using Heap Sort:");
	for(i=0;i<(e-s+1);++i)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
