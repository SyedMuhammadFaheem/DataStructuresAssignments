#include <bits/stdc++.h>  // docs faheem
using namespace std;
class CircularLinkedList;
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
class CircularLinkedList
{
	public:
	Node* head;
	CircularLinkedList()
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
        cout<<head->data<<" is the Router of the Network."<<endl;
        Node* temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"->";
        cout<<"HEAD";
    }
	void Append()
	{
		int count=1;
		while(count<=6)
		{
			cout<<"Node "<<count<<": "<<endl;
			Node* ptr=CreateNode();
			if(head==NULL)
			{
				head=ptr;
				ptr->next=head;
				count++;
				continue;
			}
			Node* temp=head;
			while(temp->next!=head)
			{
				if(temp->key==ptr->key)
            	{
                cout<<"Node of same key value exists. Please use another key!"<<endl;
                continue;
            	}
            	temp=temp->next;
			}
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=head;
			count++;
		}
	}
	void ShowConnectivity(int num)
	{
		Node* temp=head;
		while(num!=1)
		{
			temp=temp->next;
			num--;
		}
		cout<<"The Connectivity of the devices is as following: ";
		cout<<temp<<"->"<<temp->next<<endl;
	}
};
int main()
{
	CircularLinkedList C1;
	cout<<"Enter Six End Devices: "<<endl<<endl;
	cout<<"\n\n";
	C1.Append();
	cout<<"\n\n";
	C1.Traverse();
	int n;
	cout<<"\n\nEnter the number of Node you want to see the connectivity of: ";
	cin>>n;
	C1.ShowConnectivity(n);
	
	


 return 0;
}

