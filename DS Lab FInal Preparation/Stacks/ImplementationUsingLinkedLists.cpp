#include <iostream> //docs faheem
using namespace std;
#define StackSize 50
class Node
{
    public:
    int data;
    Node* next;
    Node()
    {
        this->next=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

};
class Stack
{
    public:
    Node* head;
    static int countElements;
    bool isEmpty()
    {
        if(!head)
        return true;
        return false;

    }
    bool isFull()
    {
        if(countElements==StackSize)
        return true;
        return false;

    }
    void Push(int data)
    {
        if(isFull())
        return;
        Node* newNode= new Node(data);
        countElements++;
        if(!head)
        {   
            head=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }
    void Pop()
    {
        if(isEmpty())
        return;
        countElements--;
        if(head->next)
        head=NULL;
        else
        {
            Node* temp=head;
            head=temp->next;
            temp->next=NULL;
            temp=NULL;
        }
    }
    int Peek()
    {
        if(isEmpty())
        return;
        return head->data; 

    }
    void StackTraversal()
    {
        Node* temp=head;
        if(!head->next)
        {
            cout<<head->data<<endl;
            return;
        }
        while(temp->next)
        {
            cout<<temp->data<<endl;
            temp=temp->next;

        }

    }


};
int Stack::countElements=0;
int main()
{

   
   return 0;
}