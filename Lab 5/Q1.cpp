#include <iostream> //docs faheem
using namespace std;
class Node
{
    public:
    int data,key;
    Node* next;
    Node()
    {
        data=0;
        key=0;
        next=NULL;
    }
    Node(int key,int data)
    {
        this->key=key;
        this->data=data;
        next=NULL;
    }

};
class LinkedList
{
    public:
    Node* head;
    LinkedList()
    {
        head=NULL;
    }
    Node* CreateNode()
    {
        int key,data;
        cout<<"Enter the key: ";
        cin>>key;
        cout<<"Enter the data: ";
        cin>>data;
        Node* newNode=new Node(key,data);
        return newNode;
    }
    bool isEmpty()
    {
        if(head==NULL)
        return true;
        return false;
    }
    void Display()
    {
        if(isEmpty())
        {
            cout<<"There are no nodes to display!"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void Prepend()
    {
        Node* ptr=CreateNode();
        if(isEmpty())
        {
            head=ptr;
            return;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->key==ptr->key)
            {
                cout<<"Node of same key value exists. Please use another key!"<<endl;
                return;
            }
            temp=temp->next;
        }
        ptr->next=head;
        head=ptr;
    }
    void Append()
    {
        Node* ptr=CreateNode();
        if(isEmpty())
        {
            head=ptr;
            return;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->key==ptr->key)
            {
                cout<<"Node of same key value exists. Please use another key!"<<endl;
                return;
            }
            temp=temp->next;
        }
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->next=ptr;
        ptr->next=NULL;
    }
    int Count()
    {
        int value;
        cout<<"Enter the data value you want to count: ";
        cin>>value;
        int count=0;
        if(isEmpty())
        {
            cout<<"The List is empty!"<<endl;
            return -1;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==value)
            count++;
            temp=temp->next;
        }
        cout<<"\nThe Count is: ";
        return count;
    }
};
int main()
{
    LinkedList L1;
    int choice;
    while(1)
    {
        cout<<"\n\n\nSelect any one operation to perform: ";
        cout<<"\n1) Append\n2) Prepend\n3) Display\n4) Count Same Values\n5) End\n\n";
        cout<<"Select: ";
        cin>>choice;
        if(choice==5)
        break;
        switch(choice)
        {
            case 1:
            L1.Append();
            break;
            case 2:
            L1.Prepend();
            break;
            case 3:
            L1.Display();
            break;
            case 4:
            cout<<L1.Count()<<endl;

        }

    }


   
   return 0;
}
