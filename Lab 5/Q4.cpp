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
        cout<<"NULL";
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
    void Reverse()
    {
        Node* curr=head,*prev=NULL,*next=NULL;
        while(curr!=NULL)
        {
            head=curr;
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
    }
    void SwapOddEven()
    {
        Node* Htemp=head;
        if(isEmpty())
        {
            cout<<"The Linked List is empty!"<<endl;
            return;
        }
        while(Htemp->next!=NULL)
        {
            if(Htemp->data%2!=0)
            {
                break;
            }
            Htemp=Htemp->next;
        }
        Reverse();
        Node* Ttemp=head;
        while(Ttemp->next!=NULL)
        {
            if(Ttemp->data%2==0)
            {
                break;
            }
            Ttemp=Ttemp->next;
        }
        Reverse();
        if(Htemp!=NULL || Ttemp!=NULL)
        {
            Htemp->data=Htemp->data+Ttemp->data;
            Ttemp->data=Htemp->data-Ttemp->data;
            Htemp->data=Htemp->data-Ttemp->data;
            cout<<"The swapping has been done!"<<endl;
        }
        else
        cout<<"The Linked List had only one parity!"<<endl;
    }
};
int main()
{
    LinkedList L1;
    int choice;
    while(1)
    {
        cout<<"\n\n\nSelect any one operation to perform: ";
        cout<<"\n1) Append\n2) Prepend\n3) Display\n4) Swap Odd and Even\n5) End\n\n";
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
            L1.SwapOddEven();

        }

    }


   
   return 0;
}
