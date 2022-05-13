#include<bits/stdc++.h>
using namespace std;
class Stack 
{
	int top;
	public:
	int arr[10];
	Stack() 
	{ 
		top = -1; 
	}
	bool push(int x)
	{
		if (top >= 9) 
		{
			cout << "Stack Overflow";
			return false;
		}
		arr[++top] = x;
		return true;
	}
	int pop()
	{
		if (top < 0) 
		{
			cout << "Stack Underflow";
			return 0;
		}
		int x = arr[top--];
		return x;
	}
	int peek()
	{
	if (top < 0) 
	{
		cout << "Stack is Empty";
		return 0;
	}
	int x = arr[top];
	return x;
	}
	bool isEmpty()
	{
		return (top==-1);
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
		else
		S1.push();
		i++;
		count--;
	}
	count=10;
	i=1;
	while(count)
	{
		int pop;
		cout<<"Popping the "<<i<<" element from the Stack: "<<endl;
		if(pop=S1.pop())
		cout<<"Element "<<pop<<" popped successfully from the Stack!\n"<<endl;
		else
		S1.pop();
		i++;
		count--;
	}

 return 0;
}

