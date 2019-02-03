#include<stdio.h>
#include<string.h>
int main()
{
	int n,flag,i,j;//当数字为0时表示大小写不敏感，当数字为1时表示大小写敏感。
	char a[100][101];
	char s[101];
	scanf("%s",s);
	scanf("%d",&flag); 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		j=0;
		scanf("%s",a[i]);
	}
	
	if(flag==1)
	{
		//lens=strlen(s);
		for(i=0;i<n;i++)
		{
			if(strstr(a[i],s)!=NULL)
			printf("%s\n",a[i]);
		}
	}
	else
	{
		for(i=0;i<n;i++){
			strupr(a[i]);
		}
		
		strupr(s); 
		for(i=0;i<n;i++)
		{
			if(strstr(a[i],s)!=NULL)
			printf("%s\n",a[i]);
		}
	}
	return 0;
}
