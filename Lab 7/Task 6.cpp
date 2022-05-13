#include<bits/stdc++.h>
using namespace std; 
class Node
{
	public:
		char data;
		Node* next;
	Node()
	{
		data=0;
		next=NULL;
	}
	Node(char data)
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
		int size;
	Queue(int size)
	{
		front=NULL;
		rear=NULL;
		this->size=size;
	}
	Node* CreateNode(char data)
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
	void Sort()
	{
        Node* ptr=front;
 		while(ptr)
 		{
   		    Node* ptr1=ptr->next;
         	while(ptr1)
		 	{
    		    if(ptr->data>ptr1->data)
				{
		            int temp=ptr->data;
              		ptr->data=ptr1->data;
                	ptr1->data=temp;
                }
 				ptr1=ptr1->next;
    		}
      		ptr=ptr->next;
        }
    }
	void ADDMember(char data)
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
			Sort();
		}
		cout<<"\nNode has been added!"<<endl;	
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
		cout<<"\nNode has been removed!"<<endl;
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
	Queue Q1(20);
	Q1.ADDMember('P');
	Q1.ADDMember('Q');
	Q1.ADDMember('E');
	Q1.Traverse();
	Q1.RemoveMember();
	Q1.Traverse();
	Q1.ADDMember('X');
	Q1.ADDMember('A');
	Q1.ADDMember('M');
	Q1.Traverse();
	Q1.RemoveMember();
	Q1.Traverse();
	Q1.ADDMember('P');
	Q1.ADDMember('L');
	Q1.ADDMember('E');
	Q1.Traverse();
	Q1.RemoveMember();
	Q1.Traverse();
	
 return 0;
}

