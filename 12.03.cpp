#include<iostream>
#include<sstream>
#include<string>
#include<cctype> 
using namespace std;
int main()
{
	char vowel[5]=
	{
		'A','E','I','O','U'
	};
	
	string input;
	while(getline(cin,input))
	{
		int n=input.length();
		int num[5]={0};
			for(int i=0;i<n;i++)
			{
				char s=toupper(input[i]);
				if(s=='A')	num[0]++;
				if(s=='E')	num[1]++;
				if(s=='I')	num[2]++;
				if(s=='O')	num[3]++;
				if(s=='U')	num[4]++;
			}
		for(int i=0;i<5;i++)
			cout<<vowel[i]<<": "<<num[i]<<endl;
	}
}
