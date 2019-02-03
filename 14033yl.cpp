#include <stdio.h>
#include <string.h>
int main()
{
	char geshi[53],in[21][257],budai[53],dai[53],xuanxiang[257],canshu[257][10];
	char *p=budai,*q=dai,get;
	int n,i,j,k,kk,num=0,flag=0,flag_b=0,flag_d=0,flag_c=0,mid=0;
	scanf("%s",geshi);
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		j=0;
		get=getchar();
		while(get!='\n')
		{
			if(get!='\n')
			{
				in[i][j]=get;
				j++;
			}
			get=getchar();
		}
		in[i][j]='\0';
	}
	i=0;
	while(geshi[i]!='\0')
	{
		if(geshi[i+1]==':')
		{
			*q=geshi[i];
			q=q+1;
			i+=2;
		}
		else
		{
			*p=geshi[i];
			p=p+1;
			i++;
		}
	}
	*p='\0';
	*q='\0';
	for(i=0;i<n;i++)
	{
		num=0;
		j=0;
		while(in[i][j]!='\0'&&in[i][j]!=' ')
			j++;
		printf("Case %d: ",i+1);
		while(in[i][j]!='\0')
		{
			if(in[i][j]==' ')
			{
				j++;
				continue; 
			}
			else if(in[i][j]>='a'&&in[i][j]<='z')
				break;
			else if(in[i][j]=='-')
			{
				if(in[i][j+2]!=' '&&in[i][j+2]!='\0')
					break;
				//if(flag==0)
				//{
					j++;
					flag_b=0;
					flag_d=0;
					for(k=0;k<strlen(budai);k++)
						if(budai[k]==in[i][j])
						{
							flag_b=1;
							break;
						}
					if(flag_b==1)
					{
						flag_c=0;
						for(k=0;k<num;k++)
							if(in[i][j]==xuanxiang[k])
							{
								flag_c=1;
								break;
							}
						if(flag_c==1)
						{
							j++;
							continue;
						}
						else
						{
							xuanxiang[num]=in[i][j];
							canshu[num][0]='\0';
							num++;
							j++;
						}
					}
					else
					{
						for(k=0;k<strlen(dai);k++)
							if(dai[k]==in[i][j])
							{
								flag_d=1;
								break;
							}
						if(flag_d==1)
						{
							if(in[i][j+1]=='\0')
								break;
							flag_c=0;
							for(k=0;k<num;k++)
								if(in[i][j]==xuanxiang[k])
								{
									flag_c=1;
									break;
								}
							if(flag_c==1)
							{
								j+=2;
								canshu[k][0]=' ';
								kk=1;
								while(in[i][j]!=' '&&in[i][j]!='\0')
								{
									canshu[k][kk]=in[i][j];
									kk++;
									j++;
								}
								canshu[k][kk]='\0';
							}
							else
							{
								xuanxiang[num]=in[i][j];
								j+=2;
								canshu[num][0]=' ';
								kk=1;
								while(in[i][j]!=' '&&in[i][j]!='\0')
								{
									canshu[num][kk]=in[i][j];
									kk++;
									j++;
								}
								canshu[num][kk]='\0';
								num++;
							}
						}
						else
							break;
					}
				//}
			}
		}
		
		for(k=0;k<num;k++)
		{
			printf("-%c",xuanxiang[k]);
			printf("%s",canshu[k]);
			if(k!=num-1)
				printf(" ");
		}
		if(i!=n-1)
			printf("\n");
	}
	return 0;
}

