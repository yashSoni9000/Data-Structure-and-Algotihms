#include<stdio.h>
int palindrome(int);
int main()
{
	int num,ans;
	printf("Enter any num:");
	scanf("%d",&num);
	ans=palindrome(num);
	if(ans==1)
		printf("yes");
	else
		printf("No");
	return 0;
}
int palindrome(int x)
{
	int temp=x,rev=0,mod;
	while(x>0)
	{
		mod=x%10;
		rev=(rev*10)+mod;
		x=x/10;
	}
	if(temp==rev)
		return 1;
	else
		return 0;
}
