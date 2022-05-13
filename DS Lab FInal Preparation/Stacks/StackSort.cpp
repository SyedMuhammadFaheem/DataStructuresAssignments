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
    void StackTraversal()
    {
        for(int i=top;i>-1;i--)
        {
            cout<<arr[i]<<endl;
        }
    }

};
Stack SortStack(Stack &S)
{
    Stack temp;
    while(!S.isEmpty())
    {
        int tmp=S.Peek();
        S.Pop();
        while(!temp.isEmpty() && temp.Peek()>tmp)
        {
            S.Push(temp.Peek());
            temp.Pop();
        }
        temp.Push(tmp);

    }
    return temp;
}
int main()
{

   
   return 0;
}