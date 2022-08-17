#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Node
{
    public:
    string process;
    int time,quota;
    Node* next;
    Node()
    {
        process="";
        time=quota=0;
        next=NULL;
    }
    Node(string process,int time,int quota)
    {
        this->process=process;
        this->time=time;
        this->quota=quota;
        next=NULL;
    }
    
};
class CircularLinkedList
{
    public:
    static int len;
    Node* head;
    CircularLinkedList()
    {
        head=NULL;
    }
    Node* CreateNode(string process,int time,int quota)
    {
        Node* newNode=new Node(process,time,quota);
        return newNode;
    }
    bool isEmpty()
    {
        if(head==NULL)
        return true;
        return false;
    }
    void Append(string process,int time,int quota)
    {
        len++;
        Node* n=CreateNode(process,time,quota);
        if(isEmpty())
        {
            head=n;
            n->next=head;
            return;
        }
        Node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->next=head;
    }
    void Processing()
    {
        Node* temp=head;
        while(len)
        {
            if(temp->time>0)
            {
                cout<<temp->process<<endl;
                temp->time-=temp->quota;
            }
            else
            {
            	temp=temp->next;
            	continue;
			}
            if(temp->time==0)
            len--;
            temp=temp->next;
        }
    }
};
int CircularLinkedList::len=0;
int main()
{
    CircularLinkedList L1;
    string process,temp;
    int time,quota;
    int num;
    cin>>num;
    while(num!=0)
    {
        fflush(stdin);
        cin>>process;
        cin>>time;
        cin>>quota;
        L1.Append(process,time,quota);
        --num;
    }
    L1.Processing();

   
   return 0;
}