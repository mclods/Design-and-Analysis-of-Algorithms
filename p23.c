//DAA Assignment Recursion
//Sum of n numbers using recursion
/*#include<stdio.h>
int Sum(int n)
{
	if(n==1)
		return 1;
	return n+Sum(n-1);
}
int main()
{
	int n;
	printf("\nEnter n:");
	scanf("%d",&n);
	printf("\nSum of n numbers:%d",Sum(n));
	return 0;
}*/
//Find the largest element in the array
/*#include<stdio.h>
#include<stdlib.h>
int largestEle(int A[],int s,int e)
{
	if(s==e)
		return A[s];
	int large=A[s];
	int cmp=largestEle(A,s+1,e);
	if(large<cmp)
		return cmp;
	else
		return large;
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
	printf("\nThe largest element in the array is:%d",largestEle(arr,s,e));
	return 0;
}*/
//Decimal to Binary Conversion
/*#include<stdio.h>
int decToBin(int n)
{
	if(n==0)
		return 0;
	int rem;
	rem=n%2;
	return (rem+10*decToBin(n/2));
}
int main()
{
	int n;
	printf("\nEnter the decimal number:");
	scanf("%d",&n);
	printf("\nThe Binary equivalent is:%d",decToBin(n));
	return 0;
}*/
//Multiplication of elements of array using recursion
/*#include<stdio.h>
#include<stdlib.h>
int mul(int A[],int s,int e)
{
	if(s==e)
		return A[s];
	return A[s]*mul(A,s+1,e);
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
	printf("\nThe product of elements of the array is:%d",mul(arr,0,e-s));
	return 0;
}*/
//Print Fibonacci Sequence
/*#include<stdio.h>
int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return(fib(n-1)+fib(n-2));
}
int main()
{
	int i,n;
	printf("\nEnter n:");
	scanf("%d",&n);
	printf("\nFibonacci sequence upto n:");
	for(i=0;i<=n;++i)
		printf("%d ",fib(i));
	return 0;
}*/
//Reverse a string using recursion
/*#include<stdio.h>
#include<string.h>
void strRevr(char A[],int s,int e)
{
	if(s==e)
		return;
	if(s>e)
		return;
	int temp;
	temp=A[s];
	A[s]=A[e];
	A[e]=temp;
	strRevr(A,s+1,e-1);
}
int main()
{
	char str[20];
	printf("\nEnter the string:");
	scanf("%s",str);
	int l=strlen(str);
	printf("\nl=%d",l);
	strRevr(str,0,l-1);
	printf("\nThe reversed string is:%s",str);
	return 0;
}*/
//Palindrome using recursion
/*#include<stdio.h>
#include<string.h>
int palin(char A[],int s,int e)
{
	if(s==e)
		return 1;
	if(s>e)
		return 1;
	if(A[s]!=A[e])
		return 0;
	else
		return palin(A,s+1,e-1);
}
int main()
{
	int res;
	char str[20];
	printf("\nEnter the string:");
	scanf("%s",str);
	res=palin(str,0,strlen(str)-1);
	if(res==1)
		printf("\nThe string is a palindrome");
	else
		printf("\nThe string is not a palindrome");
	return 0;
}*/
//Factorial of a number using recursion
/*#include<stdio.h>
int fact(int n)
{
	if(n==0)
		return 1;
	return n*fact(n-1);
}
int main()
{
	int n;
	printf("\nEnter n:");
	scanf("%d",&n);
	printf("\nThe factorial of n:%d",fact(n));
	return 0;
}*/
//GCD using recursion
/*#include<stdio.h>
int gcd(int a,int b)
{
	int rem=a%b;
	if(rem==0)
		return b;
	else return gcd(b,rem);
}
int main()
{
	int a,b;
	printf("\nEnter the two numbers:");
	scanf("%d%d",&a,&b);
	printf("\nThe GCD of %d and %d is:%d",a,b,gcd((a>b?a:b),(a<b?a:b)));
	return 0;
}*/
//Power of a number using recursion
/*#include<stdio.h>
int power(int n,int p)
{
	if(p==0)
		return 1;
	return n*power(n,p-1);
}
int main()
{
	int n,p;
	printf("\nEnter the number and power:");
	scanf("%d%d",&n,&p);
	printf("\n%d^%d=%d",n,p,power(n,p));
	return 0;
}*/
//Binary Search using recursion
/*#include<stdio.h>
int bSearch(int A[],int s,int e,int item)
{
	if(s<=e)
	{
		int mid=(s+e)/2;
		if(item==A[mid])
			return mid;
		if(item<A[mid])
			return bSearch(A,s,mid-1,item);
		else
			return bSearch(A,mid+1,e,item);
	}
	else
		return -1;
}
int main()
{
	int n,i,item,index;
	printf("\nEnter the size of the array:");
	scanf("%d",&n);
	int A[n];
	printf("\nEnter the elements of the array:");
	for(i=0;i<n;++i)
		scanf("%d",&A[i]);
	printf("\nEnter the element to be searched:");
	scanf("%d",&item);
	index=bSearch(A,0,n-1,item);
	if(index==-1)
		printf("\nElement not found");
	else
		printf("\nElement found at index %d",index);
	return 0;
}*/
//Reverse a number using recursion
/*#include<stdio.h>
int revNum(int n)
{
	int rem,a=n,i=1;
	while(a!=0)
	{
		rem=a%10;
		a/=10;
		i*=10;
	}
	i/=10;
	if(rem==n)
		return n;
	return rem+10*revNum(n-rem*i);
}
int main()
{
	int n;
	printf("\nEnter the no.");
	scanf("%d",&n);
	printf("\nReversed no.%d",revNum(n));
	return 0;
}*/
//Reverse a Stack using Recursion
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *next;
}*top1,*top2;
void push(struct node **root,int item)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->n=item;
	if(*root==NULL)
	{
		*root=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=*root;
		*root=temp;
	}
}
int pop(struct node **root)
{
	if(*root==NULL)
	{
		printf("\nStack Empty");
		return -1;
	}
	else if((*root)->next==NULL)
	{
		int n=(*root)->n;
		free(*root);
		*root=NULL;
		return n;
	}
	else
	{
		int n=(*root)->n;
		struct node *q=*root;
		*root=(*root)->next;
		free(q);
		q=NULL;
		return n;
	}
}
int display(struct node **root)
{
	int i=1;
	if(*root==NULL)
		printf("\nStack Empty");
	else
	{
		struct node *q=*root;
		while(q!=NULL)
		{
			printf("\n%d->%d",i,q->n);
			++i;
			q=q->next;
		}
	}

}
void stackRev()
{
	if(top1==NULL)
	{
		top1=top2;
		return;
	}
	int n=pop(&top1);
	push(&top2,n);
	stackRev();
}
int main()
{
	top1=top2=NULL;
	int n,i,a;
	printf("\nEnter the no.elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a);
		push(&top1,a);
	}
	printf("\nThe Original Stack:");
	display(&top1);
	stackRev();
	printf("\nThe Reversed Stack:");
	display(&top1);
	return 0;
}*/
//Length of the String using Recursion
/*#include<stdio.h>
int length(char A[],int s)
{
	if(A[s]=='\0')
		return 0;
	else 
		return 1+length(A,s+1);
}
int main()
{
	char str[20];
	printf("\nEnter the string:");
	scanf("%s",str);
	printf("\nThe length of the string is:%d",length(str,0));
	return 0;
}*/
//Nth Fibonacci Number
/*#include<stdio.h>
int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fib(n-2)+fib(n-1);
}
int main()
{
	int n;
	printf("\nEnter n:");
	scanf("%d",&n);
	printf("\nThe Nth term of fibonacci sequence:%d",fib(n));
	return 0;
}*/
//Largest number in an array
/*#include<stdio.h>
#include<stdlib.h>
int bigEle(int A[],int s,int e)
{
	if(s==e)
		return A[s];
	int large=A[s];
	int next=bigEle(A,s+1,e);
	if(large<next)
		return next;
	else
		return large;
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
	printf("\nThe largest element:%d",bigEle(arr,0,e-s));
	return 0;
}*/
//Sum of digits of a number
/*#include<stdio.h>
int sumDig(int n)
{
	int rem=n%10;
	if(rem==n)
		return n;
	return rem+sumDig(n/10);
}
int main()
{
	int n;
	printf("\nEnter the number:");
	scanf("%d",&n);
	printf("\nThe Sum of digits of %d=%d",n,sumDig(n));
	return 0;
}*/
//Display a Linked List in Reverse
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *next;
}*start;
void create()
{
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the element:");
	scanf("%d",&temp->n);
	if(start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
		temp->next=NULL;
	}
}
void display()
{
	struct node *q;
	if(start==NULL)
	{
		printf("\nNode Empty");
	}
	else
	{
		q=start;
		while(q!=NULL)
		{
			printf("\n->%d",q->n);
			q=q->next;
		}
	}
}
void revList(struct node *q)
{
	if(q==NULL)
		return;
	revList(q->next);
	printf("\n->%d",q->n);
}
int main()
{
	start=NULL;
	int i,n;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;++i)
		create();
	printf("\nThe List is:");
	display();
	printf("\nReversed List:");
	revList(start);
	return 0;
}*/
//Reverse a Linked List using Recursion
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *next;
}*start;
void create()
{
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the element:");
	scanf("%d",&temp->n);
	if(start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
		temp->next=NULL;
	}
}
void display()
{
	struct node *q;
	if(start==NULL)
	{
		printf("\nNode Empty");
	}
	else
	{
		q=start;
		while(q!=NULL)
		{
			printf("\n->%d",q->n);
			q=q->next;
		}
	}
}
void listRev(struct node *q,struct node *p)
{
	if(q->next==NULL)
	{
		q->next=p;
		start=q;
		return;
	}
	struct node *next=q->next;
	q->next=p;
	p=q;
	listRev(next,p);
}
int main()
{
	start=NULL;
	int i,n;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;++i)
		create();
	printf("\nThe List is:");
	display();
	printf("\nReversed List:");
	listRev(start,NULL);
	display();
	return 0;
}*/
//Display all Nodes using Recursion
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *next;
}*start;
void create()
{
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the element:");
	scanf("%d",&temp->n);
	if(start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
		temp->next=NULL;
	}
}
void display(struct node *q)
{
	if(q==NULL)
		return;
	printf("\n->%d",q->n);
	display(q->next);
}
int main()
{
	start=NULL;
	int i,n;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;++i)
		create();
	printf("\nThe List is:");
	display(start);
	return 0;
}*/
//List the number of Occurences of a Number in a Linked List
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *next;
}*start;
void create()
{
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the element:");
	scanf("%d",&temp->n);
	if(start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
		temp->next=NULL;
	}
}
void display(struct node *q)
{
	if(q==NULL)
		return;
	printf("\n->%d",q->n);
	display(q->next);
}
int noOfOccur(struct node *q,int item)
{
	if(q==NULL)
		return 0;
	if(q->n==item)
		return 1+noOfOccur(q->next,item);
	else
		return noOfOccur(q->next,item);
}
int main()
{
	start=NULL;
	int i,n,ele;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;++i)
		create();
	printf("\nThe List is:");
	display(start);
	printf("\nEnter the number:");
	scanf("%d",&ele);
	printf("\nThe no. of Occurences of %d:%d",ele,noOfOccur(start,ele));
	return 0;
}*/
//Length of a Linked List using Recursion
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *next;
}*start;
void create(int ele)
{
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->n=ele;
	if(start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
		temp->next=NULL;
	}
}
void display(struct node *q)
{
	if(q==NULL)
		return;
	printf("\n->%d",q->n);
	display(q->next);
}
int length(struct node *q)
{
	if(q==NULL)
		return 0;
	return 1+length(q->next);
}
int main()
{
	start=NULL;
	int i,n;
	n=1+(random()%(100));
	for(i=0;i<n;++i)
	{
		create(random()%101);
	}
	printf("\nThe List is:");
	display(start);
	printf("\nThe length of the list:%d",length(start));
	return 0;
}*/
//Check for Palindrome
/*#include<stdio.h>
int palin(char A[],int s,int e)
{
	if(s==e)
		return 1;
	if(s>e)
		return 1;
	if(A[s]!=A[e])
		return 0;
	else
		return palin(A,s+1,e-1);
}
int length(char A[],int s)
{
	if(A[s]=='\0')
		return 0;
	return 1+length(A,s+1);
}
int main()
{
	int n;
	char str[20];
	printf("\nEnter the string:");
	scanf("%s",str);
	n=palin(str,0,length(str,0)-1);
	if(n==0)
		printf("\nThe string is not a palindrome");
	if(n==1)
		printf("\nThe string is a palindrome");
	return 0;
}*/
//Print alternate nodes of a linked list
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *next;
}*start;
void create()
{
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the element:");
	scanf("%d",&temp->n);
	if(start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
		temp->next=NULL;
	}
}
void display(struct node *q)
{
	if(q==NULL)
		return;
	printf("\n->%d",q->n);
	display(q->next);
}
void altNodes(struct node *q)
{
	if(q==NULL)
		return;
	printf("\n->%d",q->n);
	if(q->next==NULL)
		return;
	altNodes(q->next->next);
}
int main()
{
	start=NULL;
	int i,n;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;++i)
		create();
	printf("\nThe List is:");
	display(start);
	printf("\nPrinting alternate nodes:");
	altNodes(start);
	return 0;
}*/
//Print the first capital letter of a String
/*#include<stdio.h>
void firstC(char A[],int s)
{
	if(A[s]=='\0')
	{
		printf("\nNo Capital Letters");
		return;
	}
	int n=A[s];
	if(n>=65&&n<=90)
	{
		printf("\nFirst capital letter:%c",A[s]);
		return;
	}
	firstC(A,s+1);
}
int main()
{
	char str[20];
	printf("\nEnter the string:");
	scanf("%s",str);
	firstC(str,0);
	return 0;
}*/
//Permutations of a string using recursion
#include<stdio.h>
#include<string.h>
void swap(char A[],int a,int b)
{
	int temp;
	temp=A[a];
	A[a]=A[b];
	A[b]=temp;
}
void permut(char A[],int s,int e)
{
	if(s==e)
	{
		printf("\n->%s",A);
		return;
	}
	int i;
	for(i=s;i<=e;++i)
	{
		swap(A,s,i);
		permut(A,s+1,e);
		swap(A,s,i);

	}
}
int main()
{
	char str[20];
	printf("\nEnter the string:");
	scanf("%s",str);
	printf("\nAll the permutations of the string are:");
	permut(str,0,strlen(str)-1);
	return 0;
}