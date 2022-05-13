#include <iostream> //docs faheem
using namespace std;
class Node
{
    public:
    int data,key;
    Node* next;
    Node* prev;
	Node()
    {
        data=0;
        key=0;
        next=NULL;
        prev=NULL;
    }
    Node(int key,int data)
    {
        this->key=key;
        this->data=data;
        next=NULL;
        prev=NULL;
    }

};
class DoublyLinkedList
{
    public:
    Node* head;
    DoublyLinkedList()
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
    void Traverse()
    {
        if(isEmpty())
        {
            cout<<"There are no nodes to display!"<<endl;
            return;
        }
        Node* temp=head;
        cout<<"NULL<-";
        while(temp!=NULL)
        {
        	if(temp->next!=NULL)
            cout<<temp->data<<"->""<-";
            else
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    void InsertAtEnd()
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
        ptr->prev=temp;
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
    Node* MiddleElement()
    {
    	Node* temp=head;
    	int limit=(LengthOf()/2)+1;
		int count=1;
		while(count!=limit)
		{
			temp=temp->next;
			count++;
		}
		return temp;
	}

};
int main()
{
    DoublyLinkedList L1;
    int choice;
    while(1)
    {
        cout<<"\n\n\nSelect any one operation to perform: ";
        cout<<"\n1) Traverse\n2) Insert At End\n3) Find Middle Element\n4) End\n\n";
        cout<<"Select: ";
        cin>>choice;
        if(choice==4)
        break;
        switch(choice)
        {
            case 1:
            L1.Traverse();
            break;
            case 2:
            L1.InsertAtEnd();
            break;
            case 3: 
            Node* ptr=L1.MiddleElement();
            cout<<"The Middle Element is: "<<ptr->data<<endl;
            break;
        }
    }

    
   return 0;
}
