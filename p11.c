//Palindrome check using recursion
#include<stdio.h>
#include<string.h>
int palin(char str[],int s,int e)
{
	if(s==e)
	{
		return 1;
	}
	if(str[s]!=str[e])
		return 0;
	else
	{
		return palin(str,s+1,e-1);
	}

}
int main()
{
	char str[10];
	printf("\nEnter the string:");
	scanf("%s",str);
	int res=palin(str,0,strlen(str)-1);
	if(res==0)
		printf("\nThe string is not a palindrome");
	else if(res==1)
		printf("\nThe string is a palindrome");
	return 0;
}
