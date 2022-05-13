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
    void Traverse()
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
    void InsertAtFirst()
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
    }
    void InsertAtPosition()
    {
        int key;
        cout<<"Enter the key after which you want to insert: ";
        cin>>key;
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
        while(temp->key!=key)
        {
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;

    }
    void DeleteAtFirst()
    {
        if(isEmpty())
        {
            cout<<"Linked List is empty. No node can be deleted.";
            return;
        }
        Node* temp=head;
        if(temp->next==NULL)
        {
            head=NULL;
            delete temp;
        }
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    void DeleteAtLast()
    {
        if(isEmpty())
        {
            cout<<"Linked List is empty. No node can be deleted.";
            return;
        }
        Node* temp=head;
        if(temp->next==NULL)
        {
            delete temp;
        }
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        Node* p=temp;
        temp=temp->next;
        p->next=NULL;
        delete temp;

    }
    void DeleteAtPosition()
    {
        int key;
        cout<<"Enter the key after which you want to delete: ";
        cin>>key;
        if(isEmpty())
        {
            cout<<"Linked List is empty. No node can be deleted.";
            return;
        }
        Node* temp=head;
        while(temp->key!=key || temp!=NULL)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"Node of this key value doesn't exist. Please enter another value."<<endl;
            return;
        }
        Node* ptr=temp->next;
        temp->next=ptr->next;
        delete ptr;
    }
    void Reverse()
    {
        Node* curr=head,*prev=NULL,*next=NULL;
        if(isEmpty())
        {
            cout<<"Linked List is empty. Empty List can't be reversed.";
            return;
        }
        while(curr!=NULL)
        {
            head=curr;
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        cout<<"\nThe Linked List has been reversed!"<<endl;
    }
    int Maxmimum()
    {
        int max=-99999;
        if(isEmpty())
        {
            cout<<"Linked List is empty. Maximum can't be found."<<endl;
            return -1;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            if(max<temp->data)
            max=temp->data;
            temp=temp->next;
        }
        return max;
        
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
    void Sort()
    {
        if(isEmpty())
        {
            cout<<"Linked List is empty. Sorting can't be done."<<endl;
            return;
        }
        Node* temp=head;
        if(temp->next==NULL)
        {
            cout<<"Linked List is already sorted!"<<endl;
            return;
        }
        for(int i=0;i<LengthOf();i++)
        {
            for(int j=i+1;j<LengthOf();j++)
            {
                if(temp->data>temp->next->data)
                {
                    temp->data=temp->data+temp->next->data;
                    temp->next->data=temp->data-temp->next->data;
                    temp->data=temp->data-temp->next->data;
                }
            }

        }
        cout<<"\nThe Linked List has been sorted!"<<endl;

    }
    double Mean()
    {
        double sum=0;
        if(isEmpty())
        {
            cout<<"Linked List is empty. Mean can't be found."<<endl;
            return -1;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
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
        cout<<"\n1) Traverse\n2) Insert At First\n3) Insert At End\n4) Insert At Position\n5) Delete At First\n";
        cout<<"6) Delete At End\n7) Delete At Position\n8) Maximum\n9) Mean\n10) Sort\n11) Reverse\n12) End\n\n";
        cout<<"Select: ";
        cin>>choice;
        if(choice==12)
        break;
        switch(choice)
        {
            case 1:
            L1.Traverse();
            break;
            case 2:
            L1.InsertAtFirst();
            break;
            case 3:
            L1.InsertAtEnd();
            break;
            case 4:
            L1.InsertAtPosition();
            break;
            case 5:
            L1.DeleteAtFirst();
            break;
            case 6:
            L1.DeleteAtLast();
            break;
            case 7:
            L1.DeleteAtPosition();
            break;
            case 8:
            cout<<"The Maximum element in the Linked List is: "<<L1.Maxmimum()<<endl;
            break;
            case 9:
            cout<<"The Mean of all the elements is: "<<L1.Mean()<<endl;
            break;
            case 10:
            L1.Sort();
            break;
            case 11:
            L1.Reverse();
            break;
        }
    }

    
   return 0;
}
