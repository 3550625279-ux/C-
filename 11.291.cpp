#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
struct dot 
{
	float x;
	float y;
};
float ddistance(struct dot p1,struct dot p2);
bool judge_1(struct dot *p);
bool judge_2(struct dot p1,struct dot p2,struct dot p3);
int main()
{
	struct dot p[4];
	while(cin>>p[0].x>>p[0].y)
	{
		for(int i=1;i<4;i++)
			cin>>p[i].x>>p[i].y;
		if(judge_1(p))
		{
			if(judge_2(p[0],p[2],p[1])||judge_2(p[1],p[0],p[3])||
			judge_2(p[1],p[0],p[2]))
				if(ddistance(p[0],p[2])==ddistance(p[0],p[3])||
				ddistance(p[0],p[1])==ddistance(p[0],p[3])||
				ddistance(p[0],p[1])==ddistance(p[0],p[2]))
					cout<<"Square"<<endl;
				else cout<<"Rectangle"<<endl;
			else cout<<"Other Quadrilateral"<<endl;
		}
		else cout<<"Other Quadrilateral"<<endl;
	}
}

float ddistance(struct dot p1,struct dot p2)
{
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
bool judge_1(struct dot p[])
{
	if(p[0].x+p[1].x==p[2].x+p[3].x)
	{
		if(p[0].y+p[1].y==p[2].y+p[3].y)
			if((p[2].x-p[3].x)*(p[0].y-p[1].y)!=(p[2].y-p[3].y)*(p[0].x-p[1].x))
				return true;
	} 
	if(p[0].x+p[2].x==p[1].x+p[3].x)
	{
		if(p[0].y+p[2].y==p[1].y+p[3].y)
			if((p[1].x-p[3].x)*(p[0].y-p[2].y)!=(p[1].y-p[3].y)*(p[0].x-p[2].x))
				return true;
	}
	if(p[0].x+p[3].x==p[1].x+p[2].x)
	{
		if(p[0].y+p[3].y==p[1].y+p[2].y)
			if((p[1].x-p[2].x)*(p[0].y-p[3].y)!=(p[1].y-p[2].y)*(p[0].x-p[3].x))
				return true;
	}
	return false;
	
}
bool judge_2(struct dot p1,struct dot p2,struct dot p3)
{
	if((p1.x-p2.x)*(p2.x-p3.x)+(p1.y-p2.y)*(p2.y-p3.y)==0)
		return true;
	else return false;
}
