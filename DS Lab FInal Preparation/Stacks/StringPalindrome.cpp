#include <iostream> //docs faheem
using namespace std;
#define StackSize 50
class Stack
{
    char* arr;
    int top;
    public:
    Stack()
    {
        arr=new char[StackSize];
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
    void Push(char value)
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
    char Peek()
    {
        if(isEmpty())
        return;
        return arr[top];
    }
    int Size()
    {
        return top+1;
    }
    void StackTraversal()
    {
        for(int i=top;i>-1;i--)
        {
            cout<<arr[i]<<endl;
        }
    }
    bool PalindromeCheck(string s)
    {
        Stack temp;
        int i=0;
        while(i<s.length())
        {
            temp.Push(s[i]);
            i++;
        }
        i=0;
        while(!temp.isEmpty())
        {
            if(temp.Peek()!=s[i])
            return false;
            temp.Pop();
        }
        return true;
    }

};
int main()
{

   
   return 0;
}