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
    int Append()
    {
        Node* ptr=CreateNode();
        if(isEmpty())
        {
            head=ptr;
            return 0;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->key==ptr->key)
            {
                cout<<"Node of same key value exists. Please use another key!"<<endl;
                return -1;
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
        return 0;
    }
    void StoreAverage(Node* p)
    {
        int key;
        int i=0,sum=0;
        Node* ptr=new Node;
        cout<<"Enter the key: ";
        cin>>key;
        ptr->key=key;
        while(i<4 || p!=NULL)
        {
            sum+=p->data;
            p=p->next;
            i++;
        }
        ptr->data=sum/4;
    }
};
int main()
{
    LinkedList L1;
    LinkedList L2;
    int choice;
    while(1)
    {
        cout<<"\n\n\nSelect any one operation to perform: ";
        cout<<"\n1) Append\n2) Display\n3) Store Average\n4) End\n\n";
        cout<<"Select: ";
        cin>>choice;
        if(choice==4)
        break;
        switch(choice)
        {
            case 1:
            {
                int i=1;
                cout<<"\nAppend 12 Values\n\n";
                while(i<=12)
                {
                    cout<<"Node "<<i<<": "<<endl<<endl;
                    L1.Append();
                    if(i==0)
                    i++;
                }
                break;
            }
            case 2:
            {
                int num;
                cout<<"Enter the sequence of Linked List you want to display (1 or 2): ";
                cin>>num;
                if(num==1)
                L1.Display();
                else
                L2.Display();
                break;
            }
            case 3:
            Node* temp=L1.head;
            while(temp!=NULL)
            {
                L2.StoreAverage(temp);
                temp=temp->next;
            }

        }

    }

   
   return 0;
}
