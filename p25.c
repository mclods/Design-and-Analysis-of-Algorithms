//Fractional Knapsack Problem
#include<stdio.h>
struct knp
{
	int pr;
	int wt;
};
void sort(struct knp a[],int n)
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n-1-i;++j)
		{
			if((a[j].pr/a[j].wt)<(a[j+1].pr/a[j+1].wt))
			{
				struct knp temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
float knapsack(struct knp a[],int n,int mw)
{
	int i;
	float x[n],maxprofit=0;
	for(i=0;i<n;++i)
		x[i]=0;
	i=0;
	sort(a,n);
	while(mw>0&&i<n)
	{
		if(a[i].wt<=mw)
		{
			x[i]=1;
			mw-=a[i].wt;
		}
		else
		{
			x[i]=(float)mw/a[i].wt;
			mw=0;
		}
		printf("\tx[i]=%f",x[i]);
		++i;
	}
	for(i=0;i<n;++i)
		maxprofit+=(a[i].pr*x[i]);
	return maxprofit;
}
int main()
{
	int i,n,mwt;
	printf("\nEnter Range:");
	scanf("%d",&n);
	printf("\nEnter maximum weight:");
	scanf("%d",&mwt);
	struct knp a[n];
	for(i=0;i<n;++i)
	{
		printf("\nEnter Price and Weight:");
		scanf("%d%d",&a[i].pr,&a[i].wt);
	}
	printf("\nMaximum Price:%f",knapsack(a,n,mwt));
	return 0;
}