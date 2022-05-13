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
    int LengthOf()
    {
        int count=0;
        if(isEmpty())
        {
            cout<<"Linked List is empty. Length is undefined."<<endl;
            return -1;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;

    }
    void SpecialAppend(Node* ptr)
    {
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
    void GenerateFibonacci()
    {
        int range,curr=1,prev=0,next=0,key;
        cout<<"Enter the range of the Fibonacci Sequence: ";
        cin>>range;
        Node* p1= new Node();
        cout<<"Enter the key: ";
        cin>>key;
        p1->key=key;
        p1->data=prev;
        SpecialAppend(p1);
        Node* p2= new Node();
        cout<<"Enter the key: ";
        cin>>key;
        p2->key=key;
        p2->data=curr;
        SpecialAppend(p2);
        range-=2;
        while(range)
        {
 			Node* ptr= new Node();
            cout<<"Enter the key: ";
            cin>>key;
            ptr->key=key;
            next=curr+prev;
            ptr->data=next;
			SpecialAppend(ptr); 
            prev=curr;
            curr=next;
            range--;
            Node* temp=new Node();
        }
    }
    double CountFibonacci()
    {
        double sum=0;
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data%2!=0)
            sum+=temp->data;
            temp=temp->next;
        }
        return sum/LengthOf();
    }
};
int main()
{
    LinkedList L1;
    int choice;
    while(1)
    {
        cout<<"\n\n\nSelect any one operation to perform: ";
        cout<<"\n1) Append\n2) Prepend\n3) Display\n4) Count Odd Fibonacci Values\n5) Generate Fibonacci Sequence\n6) End\n\n";
        cout<<"Select: ";
        cin>>choice;
        if(choice==6)
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
            cout<<"\nThe mean of the odd fibonacci numbers is: "<<L1.CountFibonacci()<<endl;
            break;
           	case 5:
      		L1.GenerateFibonacci();
      		

        }

    }


   
   return 0;
}
