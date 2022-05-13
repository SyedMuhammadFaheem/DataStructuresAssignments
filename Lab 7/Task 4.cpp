#include<bits/stdc++.h>
using namespace std;
#define size 10
class Queue
{
	public:
		int front,rear;
		int* arr;
	Queue()
	{
		arr=new int[size];
		front=rear=-1;
	}
	bool QueueCapacity()
	{
		if(rear==(size-1))
		return true;
		else
		return false;
	}
	void ADDMember(int value)
	{
		if(QueueCapacity())
		{
			cout<<"Queue Full. No Elements can be enqueued!"<<endl;
			return;
		}
		if(front==-1 && rear==-1)
		{
			arr[++front]=value;
			rear++;
		}
		else
		arr[++rear]=value;
		cout<<"The Element has been added to the Queue!"<<endl;
	}
	void RemoveMember()
	{
		if(front==-1 && rear==-1)
		{
			cout<<"Queue Empty. No Elements can be dequeued!"<<endl;
			return;
		}
		if(rear==front)
		front=rear=-1;
		else
		++front;
		cout<<"\nThe Element has been removed from the Queue!"<<endl;
	}
	void Traverse()
	{
		cout<<"The Elements of the Queue are: ";
		for(int i=front;i<=rear;i++)
		{
			cout<<arr[i]<<" ";
		}
	}
	
};
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

