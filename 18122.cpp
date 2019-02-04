#include<stdio.h>
int main()
{
	long long g,y,r;//信号灯等待时间
	int n;//道路段数 
	int i,flag;
	long long num,sum=0;
	long long temp1,temp2;
	long deng;
	scanf("%lld %lld %lld",&r,&y,&g);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %lld",&flag,&num);
		if(flag==0)//直路 
		{
			sum+=num;
		}
		else if(flag==1)//有灯的情况 
		{
			temp1=num-sum;
			temp2=-temp1/(r+y+g);
			deng=temp1+(temp2+1)*(r+y+g);
			deng=deng%(r+y+g);
			if(deng>r+y)
				sum=sum;
			else 
				sum=sum+deng;
		}
		else if(flag==2)
		{
			temp1=r+num-sum;
			temp2=-temp1/(r+y+g);
			deng=temp1+(temp2+1)*(r+y+g);
			deng=deng%(r+y+g);
			//printf("%d %d %d",temp1,temp2,deng);
			if(deng>r+y)
				sum=sum;
			else 
				sum=sum+deng;
		}
		else//green
		{
			temp1=y+r+num-sum;
			temp2=-temp1/(r+y+g);
			deng=temp1+(temp2+1)*(r+y+g);
			deng=deng%(r+y+g);
			if(deng>r+y)
				sum=sum;
			else 
				sum=sum+deng;
		}

	//	printf("%lld",sum);
	}
	printf("%lld",sum);
	return 0;
}
