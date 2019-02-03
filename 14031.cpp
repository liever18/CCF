#include<stdio.h>
int findreverse(int a[],int n)
{
	int num1=0,i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]+a[j]==0)
				num1++;
		}
	}
	return num1;
}
int main()
{
	int n,a[501],i,num;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	num=findreverse(a,n);
	printf("%d",num);
	return 0;
 } 
