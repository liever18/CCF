#include<stdio.h>
int main()
{
	int g,y,r;//�źŵƵȴ�ʱ��
	int n;//��·���� 
	int i,flag;
	int num,sum=0;
	scanf("%d %d %d",&r,&y,&g);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&flag,&num);
		if(flag==0||flag==1)
		{
			sum+=num;
		}
		else if(flag==2)
		{
			sum+=(num+r);
		}
		
	}
	printf("%d",sum);
	return 0;
}
