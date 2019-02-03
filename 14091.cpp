#include<stdio.h>
void nsort(int a[1001],int n)
{
	//int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
	int i, j, temp, isSorted;
//优化算法：最多进行 n-1 轮比较
	for(i=0; i<n-1; i++){
		isSorted = 1; //假设剩下的元素已经排序好了
		for(j=0; j<n-1-i; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				isSorted = 0; //一旦需要交换数组元素，就说明剩下的元素没有排序好
			}
		}			
		if(isSorted) break; //如果没有发生交换，说明剩下的元素已经排序好了
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
