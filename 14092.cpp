#include<stdio.h>
int main()
{
	int b[100][100]={0};
	int n,a[100][4],i,j,k,num=0;
	int x1,x2,y1,y2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//input_end
	for(i=0;i<n;i++)
	{
		x1=a[i][0];
		y1=a[i][1];
		x2=a[i][2];
		y2=a[i][3];
		for(j=x1;j<x2;j++)
		{
			for(k=y1;k<y2;k++)
			{
				b[j][k]=1;
			}
		}
	}
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			num=num+b[i][j];
		}
	}
	printf("%d",num);
	return 0;
}
