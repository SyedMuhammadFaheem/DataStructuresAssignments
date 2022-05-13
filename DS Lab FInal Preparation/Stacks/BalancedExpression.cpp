#include <iostream> //docs faheem
using namespace std;
#define StackSize 50
class Stack
{
    int* arr;
    int top;
    public:
    Stack()
    {
        arr=new int[StackSize];
        this->top=-1;
    }
    bool isEmpty()
    {
        if(this->top==-1)
        return true;
        else
        return false;
    }
    bool isFull()
    {
        if(this->top==StackSize-1)
        return true;
        return false;

    }
    void Push(int value)
    {
        if(isFull())
        return;
        arr[++top]=value;
    }
    void Pop()
    {
        if(isEmpty())
        return;
        arr[top]=0;
        --top;
    }
    int Peek()
    {
        if(isEmpty())
        return;
        return arr[top];
    }
    int Size()
    {
        return top+1;
    }
    bool MatchType(char ch1,char ch2)
    {
        if(ch1=='(' && ch2==')' || ch1=='{' && (ch2=='}')) || ((ch1='[') && (ch2==']')))
        return true;
        return false;
    }
    bool checkBalancedExpression(string s)
    {
        Stack S;
        int i=0;
        while(i<s.length())
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            S.Push(s[i]);
            else if(s[i]==')' || s[i]=='}' || s[i]==']' && !(S.isEmpty()))
            {
                if(!MatchType(S.Peek(),s[i]))
                return false;
                continue;
            }
            i++;
        }
        if(S.isEmpty())
        return true;

    }

};
int main()
{

   
   return 0;
}