#include<stdio.h>
sort_arr(int *a,int n,int N)
{
	int aa[4];
	aa[0]=*(a+(N-n));
	aa[1]=*(a+N+(N-n));
	aa[2]=*(a+2*N+(N-n));
	aa[3]=*(a+3*N+(N-n));
	int i;
	for(i=0;i<n;i++)
	{
//		a[0][N-n+i]=a[0][N-n+i+1];
//		a[1][N-n+i]=a[1][N-n+i+1];
//		a[2][N-n+i]=a[2][N-n+i+1];
//		a[3][N-n+i]=a[3][N-n+i+1];
		*(a+(N-n+i))=*(a+(N-n+i+1));
		*(a+N+(N-n+i))=*(a+N+(N-n+i+1));
		*(a+2*N+(N-n+i))=*(a+2*N+(N-n+i+1));
		*(a+3*N+(N-n+i))=*(a+3*N+(N-n+i+1));
	}
	*(a+(N-1))=aa[0];
	*(a+N+(N-1))=aa[1];
	*(a+2*N+(N-1))=aa[2];
	*(a+3*N+(N-1))=aa[3];
}
int main()
{
	int M ,N;
	int i,j,k,num;
	int a[4][11];
	int b[2][11];
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[j][i]);
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&b[j][i]);
		}
	}
	//¿ªÊ¼ 
	for(i=0;i<M;i++)
	{
		for(j=N-1;j>=0;j--)
		{
			if(b[0][i]>=a[0][j]&b[0][i]<=a[2][j]&b[1][i]>=a[1][j]&b[1][i]<=a[3][j])
			{
				printf("%d\n",j+1);
				sort_arr(&a[0][0],j+1,N);
				break;
			}
			if(j==0)
				printf("IGNORED\n");
		}
	}
	return 0;
}
