#include<stdio.h>
//void n_four(int n,int a[1001][4])
//{
//	
//}
long long int zuhe(int a,int b)
{
	long long int c=1;
	int i,j;
	for(i=b+1;i<=a;i++)
	{
		c=c*i;
	}
	for(i=1;i<=a-b;i++)
	{
		c=c/i;
	}
	return c;
}
int main()
{
	int n,out,i;
	//int a[1001][4];
	long long int sum=0;
	scanf("%d",&n);
	//第一位一定是2
//	n_four(n,a);
	for(i=2;i<n-1;i++)
	{
		sum=sum+zuhe(n-1,i)*(i-1)*(n-1-i);
	}
	out=sum%1000000007;
	printf("%d",out);
	return 0;
}
