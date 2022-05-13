#include<bits/stdc++.h>
using namespace std;
#define size 10 
class Node
{
	public:
		int data;
		Node* next;
	Node()
	{
		data=0;
		next=NULL;
	}
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}
	
};
class Queue
{
	public:
		static int count;
		Node* front;
		Node* rear;
	Queue()
	{
		front=NULL;
		rear=NULL;
	}
	Node* CreateNode(int data)
	{
		Node* new_Node=new Node(data);
		return new_Node;
	}
	bool QueueCapacity()
	{
		if(count==size)
		return true;
		else
		return false;
	}
	void ADDMember(int data)
	{
		if(QueueCapacity())
		{
			cout<<"Queue Full. No Elements can be enqueued!"<<endl;
			return;
		}
		Node* n1=CreateNode(data);
		if(front==NULL && rear==NULL)
		{
			front=n1;
			rear=n1;
		}
		else
		{
			rear->next=n1;
			rear=n1;
		}	
		count++;
	}
	void RemoveMember()
	{
		if(front==NULL && rear==NULL)
		{
			cout<<"Queue Empty. No Elements can be dequeued!"<<endl;
			return;
		}
		Node* temp=front;
		if(front==rear)
		{
			front=NULL;
			rear=NULL;
		}
		else
		{
			front=temp->next;
			temp=NULL;
		}
		count--;
	}
	void Traverse()
	{
		Node* temp=front;
		if(front==rear)
		{
			cout<<temp->data<<"->"<<"NULL"<<endl;
		}
		while(temp!=rear->next)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
};
int Queue::count=0;
int main()
{
	Queue Q1;
	Q1.ADDMember(5);
	Q1.ADDMember(6);
	Q1.ADDMember(7);
	Q1.Traverse();
	Q1.RemoveMember();
	Q1.Traverse();
	
 return 0;
}

