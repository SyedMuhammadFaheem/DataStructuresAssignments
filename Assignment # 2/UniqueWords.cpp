#include <iostream>
#include <string>
using namespace std;
class Node
{
    public:
    string data;
    Node* right;
    Node* left;
    Node()
    {
        data="";
        right=NULL;
        left=NULL;
    }
    Node(string data)
    {
        this->data=data;
        right=NULL;
        left=NULL;
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
    Node* CreateNode(string data)
    {
        Node* newNode=new Node(data);
        return newNode;
    }
    bool isEmpty()
    {
        if(head==NULL)
        return true;
        return false;
    }
    void Append(string data)
    {
        Node* n=CreateNode(data);
        if(isEmpty())
        {
            head=n;
            return;
        }
        Node* temp=head;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=n;
        n->left=temp;
    }
    void RemoveDuplicates()
    {
        Node* temp=head;
        while(temp)
        {
            Node* temp1=temp->right;
            while(temp1)
            {
                if(temp->right)
                {
                    if(temp->data==temp1->data)
                    {
                        temp->left->right=temp->right;
                        temp->right->left=temp->left;
                    }
                }
                temp1=temp1->right;
            }
            temp=temp->right;
        }

    }
    void Sort()
    {
        Node* temp=head;
        bool f1=false;
        bool f2=false;
        while(temp)
        {
            Node* temp1=temp->right;
            while(temp1)
            {
                if(temp->data[0]>=65 && temp->data[0]<=90)
                {
                    temp->data[0]=temp->data[0]+32;
                    f1=true;
                }
                if(temp1->data[0]>=65 && temp1->data[0]<=90)
                {
                    temp1->data[0]=temp1->data[0]+32;
                    f2=true;
                }
                if(temp->data>temp1->data)
                {
                    if(f1)
                    {
                        temp->data[0]=temp->data[0]-32;
                        f1=false;
                    }
                    if(f2)
                    {
                        temp1->data[0]=temp1->data[0]-32;
                        f2=false;
                    }
                    string hold=temp->data;
                    temp->data=temp1->data;
                    temp1->data=hold;
                }
                if(f1)
                {
                    temp->data[0]=temp->data[0]-32;
                    f1=false;
                }
                if(f2)
                {
                    temp1->data[0]=temp1->data[0]-32;
                    f2=false;
                }
                temp1=temp1->right;
            }
            temp=temp->right;
        }

    }
    void Traverse()
    {
        if(isEmpty())
        return;
        Node* temp=head;
        while(temp)
        {
            cout<<temp->data<<endl;
            temp=temp->right;
        }
    }
};
int main()
{
    LinkedList L1;
    string input,temp;
    fflush(stdin);
    getline(cin,input);
    int i=0;
    while(1)
    {
        if(input[i]==' ' || input[i]=='\0')
        {
            L1.Append(temp);
            temp="";
            if(input[i]=='\0')
            break;
        }
        else
        temp+=input[i];
        i++;
    }
    L1.RemoveDuplicates();
    L1.Sort();
    L1.Traverse();


   
   return 0;
}