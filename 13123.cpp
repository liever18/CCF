#include<stdio.h>
int min(int a[],int i,int j)
{
	int minnum=10001;
	int k;
	for(k=i;k<=j;k++)
	{
		if(minnum>a[k])
			minnum=a[k];
	}
	return minnum;
}
int max(int a[],int n)
{
	int num=0,i,j,temp=0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			temp=(j+1-i)*min(a,i,j);
			if(temp>num)
				num=temp;
		}
	}
	
	return num;
}
int main()
{
	int n,i,num;
	int a[1001];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	num=max(a,n);
	printf("%d",num);
	return 0;
}
