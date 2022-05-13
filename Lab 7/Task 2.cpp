#include<bits/stdc++.h>
using namespace std;
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
class Stack 
{
	public:
	Node* head;
	Node* CreateNode(int data)
	{
		Node* newNode=new(nothrow) Node(data);
		return newNode;
	}
	Stack() 
	{ 
		head=NULL; 
	}
	bool push(int x)
	{
		Node* ptr=CreateNode(x);
		if (!(CreateNode(x))) 
		{
			cout << "Stack Overflow";
			return false;
		}
		if(head==NULL)
		head=ptr;
		else
		{
			Node* temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
		}
		return true;
	}
	int pop()
	{
		if (head==NULL) 
		{
			cout << "Stack Underflow";
			return 0;
		}
		Node* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		int x = temp->data;
		temp=NULL;
		return x;
	}
	void ReverseStack()
	{
		if(head==NULL)
		{
			cout<<"Stack is Empty!"<<endl;
			return;
		}
		Node* curr=head;
		Node* prev=NULL;
		Node* next=NULL;
		while(curr!=NULL)
		{
			head=curr;
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		
	}
	void DisplayStack()
	{
		ReverseStack();
		Node* temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
		ReverseStack();
		
	}
	void DisplayReverseStack()
	{
		Node* temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
		
	}
};
int main()
{
	Stack S1;
	int count=10;
	cout<<"Pushing values into the Stack!\n"<<endl;
	int i=1;
	while(count)
	{
		int val;
		cout<<"Enter the "<<i<<" value into the Stack: ";
		cin>>val;
		if(S1.push(val))
		cout<<"Element pushed into the Stack!\n"<<endl;
		i++;
		count--;
	}
	cout<<"\n\nDisplaying the Stack in LIFO Order!\n\n";
	S1.DisplayStack();
	cout<<"\n\nDisplaying the Stack in REVERSE Order!\n\n";
	S1.DisplayReverseStack();
	
	cout<<"\n\nPopping the Top-most Element: "<<S1.pop();

 return 0;
}

