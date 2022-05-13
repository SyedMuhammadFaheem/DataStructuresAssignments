#include<bits/stdc++.h>
using namespace std;
class Stack 
{
	public:
	int top;
	char arr[500];
	Stack() 
	{ 
		top = -1; 
	}
	bool push(char x)
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
	bool isEmpty()
	{
		return (top<0);
	}
	int CheckPrecedence(char x)
	{
		if(x=='^')
		return 3;
		else if(x=='*' || x=='/')
		return 2;
		else if(x=='+' || x=='-')
		return 1;
		else
		return 0;
	}
	bool isOperator(char x)
	{
		if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
		return true;
		return false;
	}
	bool isDigit(char x)
	{
		if(x>='0' && x<='9')
		return true;
		return false;
	}
	bool isAlpha(char x)
	{
		if((x>='a' && x<='z') || (x>='A' && x<='Z'))
		return true;
		return false;
	}
	void InfixToPostfix(string str)
	{
		char *post=new char[str.length()];
		int i=0,j=0;
		while(str[i]!='\0')
		{
			if(str[i]=='(')
			{
				push(str[i]);
			}
			else if(isOperator(str[i]))
			{
 	            while(isOperator(arr[top]) && CheckPrecedence(arr[top])>=CheckPrecedence(str[i]))
				{
	                post[j]=pop();
					j++;
				}
				push(str[i]);
				
			}
			else if(isAlpha(str[i]) || isDigit(str[i]))
			{
				post[j]=str[i];
				j++;
			}
			else if(str[i]==')')
			{
				while(arr[top]!='(')
				{
					post[j]=pop();
					j++;
				}
				pop();
			}
			i++;
		}
		while(!(isEmpty()))
		{
		    post[j]=pop();
			j++;
		}	
		i=0;
		cout<<"The Postfix Expression is: ";
		while(post[i]!='\0')
		{
			cout<<post[i];
			i++;
		}
	}
};
int main()
{
	Stack S1;
	string str;
	cout<<"Enter the Infix Expression: ";
	getline(cin,str);
	S1.InfixToPostfix(str);
 return 0;
}

