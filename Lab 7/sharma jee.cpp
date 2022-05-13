#include<iostream>
using namespace std;
class Stack {
		int top;	
		public:
			char a[10]; // Maximum size of Stack
			Stack() { top = -1; }
			bool push(char x);
			char pop();
			char peek();
			bool isEmpty();
			bool isOperator(char c);
			int prec(char c);
			string infixToPostfix(string exp);
};
		bool Stack::push(char x)
		{
			if (top >= (10 - 1)) 
			{
			cout << "Stack Overflow";
			return false;
			}
		else 
		{
			a[++top] = x;
			cout << x << " pushed into stack\n";
			return true;
		}
			}
	char Stack::pop()
	{
		if (top < 0) 
		{
		cout << "Stack Underflow";
		return 0;
		}
	
		else 
		{
			char x = a[top--];
			return x;
		}
    }
	char Stack::peek()
	{
		if (top < 0) 
		{
			cout << "Stack is Empty";
			return 0;
		}
		else
		{
			char x = a[top];
			return x;
		}
	}
	bool Stack::isEmpty()
	{
		return (top < 0);
	}
	bool Stack::isOperator(char c)
	{
		if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Stack::prec(char c)
	{
		if(c == '^')
		return 3;
		else if(c == '*' || c == '/')
		return 2;
		else if(c == '+' || c == '-')
		return 1;
		else
		return -1;
	}
	string Stack::infixToPostfix(string exp)
	{
		string postfix;
		for(int i=0;i<exp.length();i++)
		{
			if((exp[i]>='a' && exp[i]<='z') || exp[i]>='A' && exp[i]>='Z')
			{
				postfix+=exp[i];
			}
			else if(exp[i]=='(')
			{
				push(exp[i]);
			}
			else if(exp[i]==')')
			{
				while((peek()!='(') && (!isEmpty()))
				{
					char temp=peek();
					postfix+=temp;
					pop();
				}
			}
			else if(isOperator(exp[i]))
			{
				if(isEmpty())
				{
					push(exp[i]);
				}
				else
				{
					if(prec(exp[i])>prec(peek()))
					{
						push(exp[i]);
					}
					else if((prec(exp[i])==prec(peek())) && (exp[i]=='^'))
					{
						push(exp[i]);
					}
					else
					{
						while((!isEmpty())&& (prec(exp[i])<=prec(peek())))
						{
							char temp=peek();
							postfix+=temp;
							pop();	
						}
						push(exp[i]);	
					}	
				}
			}
			
		}
		while(!isEmpty())
		{
			postfix+=peek();
			pop();
		}
		return postfix;
	}
	
int main()
{
	Stack s1;
	string postfix;
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	postfix=s1.infixToPostfix(exp);
	cout<<postfix;
}
