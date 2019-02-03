#include<stdio.h>
int main()
{
	int a[3];
	int b[9];
	int i,num=0;
	char X;
	scanf("%d-%d-%d-%c",&a[0],&a[1],&a[2],&X);
	b[0]=a[0];
	b[1]=a[1]/100;
	b[2]=(a[1]/10)%10;
	b[3]=a[1]%10;
	b[4]=a[2]/10000;
	b[5]=a[2]/1000%10;
	b[6]=a[2]/100%10;
	b[7]=a[2]/10%10;
	b[8]=a[2]%10;
	for(i=0;i<9;i++)
	{
		num=num+b[i]*(i+1);
	}
	num=num%11;
	if(num==10)
	{
		if(X=='X')
			{printf("Right");
			return 0;
			}
		else
		{	printf("%d-%d%d%d-%d%d%d%d%d-X",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8]);
		return 0;
			}
	}
	if((X-'0')==num)
		printf("Right");
	else
		printf("%d-%d%d%d-%d%d%d%d%d-%d",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],num);
	return 0;
}
