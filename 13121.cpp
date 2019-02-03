#include<stdio.h>
int a[1001];
int n;
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (j = 0; j < n - 1; j++)
        for (i = 0; i < n - 1 - j; i++)
        {
            if(a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
}
void max(int a[],int n)
{
	int ii,count=1,kk,jj;//jjÊýÖµ£¬kk count 
	for(ii=1;ii<n;ii++)
	{
		if(a[ii]==a[ii-1]){
			kk++;
			//jj=a[ii];
		}
		else
		{
			kk=1;
			//jj=a[ii];	
		}
		if(kk>count){
			jj = a[ii];
			count=kk;
		}	
	}
	printf("%d",jj); 
}
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble_sort(a,n);
	max(a,n);
	return 0;
}
