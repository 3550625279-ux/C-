#include<iostream>
#include<string>
using namespace std;
struct staff
{
	int code;
	int age;
	char gender;
	struct staff*next;
};
struct staff* CreateList(int n);
void Output(struct staff*head);
void count_gender(struct staff*head);
void insert(struct staff*&head,struct staff* data);
void Delete(struct staff*&head,int code);
void retire(struct staff*&head,struct staff*&retirelist);
void deleteList(struct staff *&head); 
int main()
{
	int n;
	while(cin>>n)
	{
		struct staff *head=CreateList(n);
		struct staff* retirelist=NULL;
		string command;
		while(cin>>command)
		{
			if(command=="output")
				Output(head);
			if(command=="count_gender")
				count_gender(head);
			if(command=="insert")
			{
				struct staff*data=new struct staff;//一定要记得加new 
				cin>>data->code>>data->age>>data->gender;
				insert(head,data);
			}
			if(command=="delete")
			{
				int code;
				cin>>code;
				Delete(head,code);
			}
			if(command=="retire")
				retire(head,retirelist); 
			if(command=="end")
			{
				deleteList(head);
				deleteList(retirelist);
				break;
			}
			cout.flush() ;
		}
	}
}

struct staff*CreateList(int n)
{
	struct staff*head=NULL;
	struct staff*s=new struct staff;
	cin>>s->code>>s->age>>s->gender;
	n--;
	head=s;
	while(n--)
	{
		struct staff*p=new struct staff;
		cin>>p->code>>p->age>>p->gender;
		s->next=p;
		s=p;
	}
	s->next=NULL;
	return head; 
}

void Output(struct staff*head)
{
	while(head!=NULL)
	{
		cout<<head->code<<' '<<head->age<<' '<<head->gender<<endl;
		head=head->next;
	}
}

void count_gender(struct staff*head)
{
	int countM=0,countF=0;
	while(head!=NULL)
	{
		if(head->gender=='M')
			countM++;
		else
			countF++;
		head=head->next;
	}
	cout<<countM<<' '<<countF<<endl;
}

void insert(struct staff*&head,struct staff*data)
{
	data->next=NULL;
	if(head==NULL)
	{
		head=data;
		return;
	}
	struct staff* curr=head; 
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=data;
}
void Delete(struct staff*&head,int code)
{
	struct staff*prev=NULL,*curr=head;
	while(curr!=NULL)
	{
		if(curr->code==code)
		{
			if(head->code==code)
				head=head->next;
			else
				prev->next=curr->next;
			delete curr;
			return;
		}
		prev=curr;
		curr=curr->next;
	}
}

void retire(struct staff*&head,struct staff*&retirelist)
{
	struct staff*curr=head;
	struct staff* rhead=NULL,*s=NULL,*p=NULL;
	while(curr!=NULL)
	{
		if((curr->gender=='M'&&curr->age>=60)||(curr->gender=='F'&&curr->age>=55))
		{
			struct staff*temp=new struct staff;
			*temp=*curr;
			insert(retirelist,temp);
			Delete(head,curr->code);
		}
		curr=curr->next;
	}
	Output(retirelist);
}
void deleteList(struct staff *&head)
{
	while(head!=NULL)
	{
		struct staff*temp=head;
		head=head->next;
		delete temp;
	}
} 

