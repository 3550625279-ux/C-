#include<iostream>
#include<algorithm>
#include<climits> 
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int *num=new int[n];
		for(int i=0;i<n;i++)
			cin>>num[i];
		/*
		int max1=num[0],max2=num[0];
		for(int i=1;i<n;i++)
		{
			for(int j=0;j+i<n;j++)
			{
				int temp=0;
				for(int k=j;k<j+i;k++)
				{
					temp+=num[k];
				}
				max2=(max2>temp)?max2:temp;
			}
			max1=(max1>max2)?max1:max2;
		}
		cout<<max1<<endl;
		*/
		/*int current_max=num[0],global_max=num[0];
		for(int i=0;i<n;i++)
		{
			current_max=max(num[i],current_max+num[i]);
			global_max=max(current_max,global_max);
		}
		cout<<global_max<<endl;
		*/
		
		int *num_i=new int [n+1];
		for(int i=0;i<n;i++)
			num_i[i+1]=num_i[i]+num[i];
		int min_num_i=num_i[0],global_max=INT_MIN;
		for(int i=0;i<n;i++)
		{
			global_max=max(global_max,num_i[i]-min_num_i);
			min_num_i=min(num_i[i],min_num_i);
		}
		cout<<global_max<<endl;
		delete[] num;
		delete[] num_i; 
	}
}

这是一个计算数组连续数之和的程序
