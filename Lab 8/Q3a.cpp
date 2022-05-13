#include <iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* left;
		Node* right;
	Node()
	{
		data=0;
		left=right=NULL;
	}
	Node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
	
};
class BST
{
	public:
		Node* root;
	BST()
	{
		root=NULL;
	}
	Node* CreateNode(int data)
	{
		Node* newNode=new Node(data);
		return newNode;
	}
	void InOrder(Node* root)
	{
		if(root)
		{
			InOrder(root->left);
			cout<<root->data<<" ";
			InOrder(root->right);
		}
	}
    void PreOrder(Node* root)
	{
		if(root)
		{
			cout<<root->data<<" ";
			PreOrder(root->left);
			PreOrder(root->right);
		}
	}
	void Insert(int data)
	{
        Node* newNode=CreateNode(data);
		if(root==NULL)
		{
			root=newNode;
			return;
		}
		Node* ptr=root;
		Node* prev=NULL;
		while(root)
		{
			prev=root;
			if(newNode->data<root->data)
			root=root->left;	
			else
			root=root->right;
		}
		if(newNode->data<prev->data)
		{
			prev->left=newNode;
		}
		else
		prev->right=newNode;
		root=ptr;
	}
};
int main()
{
	BST T1;
	T1.Insert(28);
    T1.Insert(96);
	T1.Insert(69);
    T1.Insert(420);
	T1.Insert(25);
    cout<<"\n\nThe Recursive PreOrder Traversal of the values in the BST is: ";
    T1.PreOrder(T1.root);
	cout<<"\nThe Recursive InOrder Traversal of the values in the BST is: ";
    T1.InOrder(T1.root);
	cout<<"\n";
 return 0;
}

