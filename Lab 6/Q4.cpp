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
    void InsertAtEnd(int count)
    {
    	while(count)
		{
			
        Node* ptr=CreateNode();
        if(isEmpty())
        {
            head=ptr;
            count--;
            continue;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->key==ptr->key)
            {
                cout<<"Node of same key value exists. Please use another key!"<<endl;
                continue;
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
	 	count--;    
    }
	 }
    int count()
    {
    	cout<<"\n\n";
    	Node* temp=head;
    	int count=0,num=0,data=temp->data;
    	cout<<"The Original Linked List on which the algorithm was applied was:  ";
    	while(num<3)
    	{
    		cout<<temp->data<<"->";
    		temp=temp->next;
    		count++;
    		num++;
		}
		num=1;
    	while(temp->data!=data)
    	{
    		if(num==3)
    		{
    			count++;
    			num=0;
				cout<<temp->data<<"->";
			}
    		temp=temp->next;
    		++num;
		}
		cout<<"NULL"<<endl<<endl;
		return count;
	}

};
int main()
{
    DoublyLinkedList L1;
    int count;
    cout<<"Enter the number of elements of the output list: ";
    cin>>count;
    L1.InsertAtEnd(count);
    cout<<"The count of the elements of the original linked list is: "<<L1.count()<<endl;
    
   return 0;
}
