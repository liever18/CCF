#include<stdio.h>
void nsort(int a[1001],int n)
{
	//int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
	int i, j, temp, isSorted;
//�Ż��㷨�������� n-1 �ֱȽ�
	for(i=0; i<n-1; i++){
		isSorted = 1; //����ʣ�µ�Ԫ���Ѿ��������
		for(j=0; j<n-1-i; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				isSorted = 0; //һ����Ҫ��������Ԫ�أ���˵��ʣ�µ�Ԫ��û�������
			}
		}			
		if(isSorted) break; //���û�з���������˵��ʣ�µ�Ԫ���Ѿ��������
	}
}
int count(int a[1001],int n)
{
	int i,num=0;
	for(i=0;i<n-1;i++)
	{
		if(a[i+1]-a[i]==1)
		{
			num++;
		}
	}
	return num;
}
int main()
{
	int a[1001],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	nsort(a,n);
	printf("%d",count(a,n));
	return 0;
}
