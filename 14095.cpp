#include<stdio.h>
#include<math.h>
int main()
{
	int n,m,temp;
	scanf("%d %d",&n,&m);
	if(n<=6&&m<=6)
	{
		if(n==1)
			printf("0");
		else if(n==2)
		{
			if(m==3)
				printf("2");
			else if(m==6)
				printf("4");
			else
				printf("0");
		}
		else if(n==3)
		{
			if(m==2)
				printf("2");
			else if(m==4)
				printf("4");
			else if(m==6)
				printf("8");
			else
				printf("0");
		}
		else if(n==4)
		{
			if(m==3)
				printf("4");
			else if(m==6)
				printf("16");
			else
				printf("0");
		}
		else if(n==5)
		{
			if(m==6)
				printf("%d",2*8*4);
			else
				printf("0");
		}
		else
		{
			if(m==2)
				printf("4");
			else if(m==3)
				printf("8");
			else if(m==4)
				printf("16");
			else if(m==5)
				printf("%d",2*8*4);
			else //m==6Ê±µÈÓÚ£¿ 
				printf("0");
		}
		return 0;	
	} 
	if(m==1)
	{
		printf("0");
	}
	else if(m==2)
	{
		if(n%3==0)
		{
			temp=pow(2,(n/3));
			printf("%d",temp);
		}
		else
			printf("0");
	}
	else if(m==3)
	{
		if(n%2==0)
			printf("%d",pow(2,(n/2)));
		else
			printf("0");
	}
	else if(m==4)
	{
		if(n%2==0)
			printf("%d",pow(2,n));
		else
			printf("0");
	}
	else if(m==5)
	{
		
	}
	else
		printf("0");
	return 0;
}
