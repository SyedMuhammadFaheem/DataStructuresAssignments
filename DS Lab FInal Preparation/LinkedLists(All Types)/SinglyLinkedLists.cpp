#include <iostream> //docs faheem
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node()
    {
        this->next=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

};
class SinglyLinkedList
{
    public:
    Node* root;
    SinglyLinkedList()
    {
        this->root=NULL;
    }
    void Append(int data)
    {
        Node* newNode=new Node(data);
        if(!root)
        {
            root=newNode;
            return;
        }
        Node* temp=root;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newNode;

    }
    void Prepend(int data)
    {
        Node* newNode=new Node(data);
        if(!root)
        {
            root=newNode;
            return;
        }
        newNode->next=root;
        root=newNode;
    }
    void InsertInBetween(int data,int pos)
    {

    }

};
int main()
{

   
   return 0;
}