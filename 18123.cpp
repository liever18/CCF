#include<iostream>
#include<list>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
long long a[10001][5];
//long long temp_long1=256*256*256*64;
long long temp_long2;
long long hebing;
long long b[10001];
list<long long>b_list(1);

int main()
{
	char s_temp[30];
	int i,j,k;
	scanf("%d",&n);
	int temp1,temp2;
	//cout<<sizeof(int);
	for(i=0;i<n;i++)
	{
		scanf("%s",s_temp);
		if(strchr(s_temp,'/')==NULL) //无后缀 
		{
			for(k=0,j=0;k<strlen(s_temp);k++)//k为遍历，j是第几节 
			{
				if(s_temp[k]!='.')
				{
					a[i][j]=a[i][j]*10+s_temp[k]-'0';
				}
				else
				{
					j++;
				}
			}
			a[i][4]=(j+1)*8;
		}
		else//有后缀 
		{
			for(k=0,j=0;k<strlen(s_temp);k++)
			{
				if(s_temp[k]=='/')
				{
					j=4;
				}
				else if(s_temp[k]=='.')
				{
					j++;
				}
				else
				{
					a[i][j]=a[i][j]*10+s_temp[k]-'0';
				}
			}
		}
	}
	for(i=0;i<n;i++)//把IP地址存入一个long long int数组里 再排序 
	{
		b[i]+=a[i][4];
		b[i]+=(int)a[i][3]*64;
		b[i]+=(int)a[i][2]*256*64;
		b[i]+=(int)a[i][1]*256*256*64;
		temp_long2=a[i][0]<<30;
		b[i]+=temp_long2;
	}
	sort(b,b+n);
	for(i=0;i<n;i++)
	{
		b_list.push_back(b[i]);
	}
	b_list.erase(b_list.begin());
  	list<long long>::iterator it = b_list.begin();
  	list<long long>::iterator it1 = b_list.begin();
  	list<long long>::iterator p_temp;
//开始合并 从小到大合并

	it = b_list.begin();
	p_temp=it;
	p_temp++;
	while(p_temp!=b_list.end())
	{
		
		temp1=(*it)&63;
		temp2=(*p_temp)&63;
		//cout<<" "<<123<<" "<<temp1<<" "<<temp2<<endl;
		if(temp1<=temp2)//判断掩码长度 
		{
			temp1=min(temp1,temp2);
			if(((*it)>>(38-temp1))==((*p_temp)>>(38-temp1)))
			{
				b_list.erase(p_temp);
				//cout<<"delete"<<endl;
			}
			else
				it++;
		}
		else
		{
			it++;
		}
		
		p_temp=it;
		p_temp++;
	}

    //同级合并
    it = b_list.begin();
	p_temp=it;
	p_temp++;
	while(p_temp!=b_list.end())
	{
		temp1=(*it)&63;
		temp2=(*p_temp)&63;
		//cout<<" "<<123<<" "<<temp1<<" "<<temp2<<endl;
		if(temp1==temp2)//判断掩码长度 
		{	
			if(((*it)>>(38-temp1+1))==((*p_temp)>>(38-temp1+1)))
			{
				hebing=(*it)&(*p_temp);
				hebing--;
				//cout<<"hebing it p_temp:"<<hebing<<" "<<(*it)<<" "<<(*p_temp)<<endl;	
				//cout<<"it p_tmep:"<<(*it)<<" "<<(*p_temp)<<endl;
				b_list.insert(it,hebing);
				b_list.erase(it++);
				//it1=it;
				b_list.erase(it++);
				//p_temp=it;
				it--;			
				it1=it;
				it1--;
				if(*it1==0)
				{
					p_temp=it;
					p_temp++;
				}
				else
				{
					it=it1;
					p_temp=it;
					p_temp++;
				}
				continue;
			}
			else
			{
				it++;
			}
		}
		else
		{
			it++;
		}
		p_temp=it;
		p_temp++;
	} 
    //输出
    it=b_list.begin();
	 while(it != b_list.end())
	{
        //printf("%lld\t",*it);
        cout<<((*it)>>30)<<"."<<(((*it)>>22)%256)<<"."<<(((*it)>>14)%256)<<"."<<(((*it)>>6)%256)<<"/"<<((*it)&63)<<endl;
        it++;   
    }
	return 0;
}
