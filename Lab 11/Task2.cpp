#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Node
{
    public:
    char data;
    Node* next;
    Node* edges;
    Node()
    {
        data=0;
        next=edges=NULL;
    }
    Node(char data)
    {
        this->data=data;
        next=edges=NULL;

    }

};
class Graph
{
    public:
        Node* source;
    Graph()
    {
    	source=NULL;
	}
    Node* InsertNode(char data)
    {
        Node* newNode=new Node(data);
        if(!source)
        {
            source=newNode;
            return newNode;
        }
        Node* temp=source;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        return newNode;
    }
    void addEdge(Node* n1,Node* n2)
    {
    	 Node* newNode1=new Node(n2->data);
    	Node* newNode=new Node(n1->data);
        Node* temp=n1;
        if(!temp->edges)
        temp->edges=newNode1;
        else
        {
            while(temp->edges->next)
            {
                temp->edges=temp->edges->next;
            }
            temp->edges->next=newNode1;
        }
      
    	temp=n2;
        if(!temp->edges)
        temp->edges=newNode;
        else
        {
            while(temp->edges->next)
            {
                temp->edges=temp->edges->next;
            }
            temp->edges->next=newNode;
        }
    }
    void PrintAdjacent()
    {
        int i=1;
        Node* temp=source;
        while(temp)
        {
        	cout<<"Node "<<i<<"("<<temp->data<<")->";
            Node* connections=temp->edges;
            while(connections)
            {
                cout<<connections->data<<"->";
                connections=connections->next;
            }
            cout<<endl;
            temp=temp->next;
            i++;
        }
    }

};
int main()
{
    Graph G;
    Node* a;
    Node* b;
    Node* c;
    Node* d;
    Node* e;
	a=G.InsertNode('A');
    b=G.InsertNode('B');
    c=G.InsertNode('C');
    d=G.InsertNode('D');
    e=G.InsertNode('E');
    G.addEdge(a,b);
    G.addEdge(b,c);
    G.addEdge(a,c);
    G.PrintAdjacent();
	return 0;
}
