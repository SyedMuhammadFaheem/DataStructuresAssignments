#include <iostream>
#include <stack> 
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
    void InOrder()
	{
		stack <Node*> s;
        Node* temp=root;
		while(!s.empty() || temp)
		{
			if(temp)
			{
				temp=s.top();
				s.pop();
				cout<<temp->data<<" ";
				temp=temp->left;
			}
			else 
			{
				s.push(temp);
				temp=temp->right;
			}
		}
	}
//void InOrder()
//	{
//		stack <Node*> s;
//        Node* temp=root;
//        if(!temp)
//        s.push(temp);
//		while(!s.empty())
//		{
//			if(temp->left)
//			{
//				s.push(temp);
//				temp=temp->left;
//			}
//			else
//			{
//				temp=s.top();
//				s.pop();
//				cout<<temp->data<<" ";
//				temp=temp->right;
//			}
//		}
//	}
	void PreOrder()
	{
		stack <Node*> s;
        Node* temp;
		if(root)
		s.push(root);
		while(!s.empty())
		{
			if(temp->left)
			s.push(temp->left);
			if(temp->right)
			s.push(temp->right);
			temp=s.top();
			s.pop();
			cout<<temp->data<<" ";
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
    cout<<"\n\nThe Iterative PreOrder Traversal of the values in the BST is: ";
//	T1.PreOrder();
	cout<<"\nThe Iterative InOrder Traversal of the values in the BST is: ";
	T1.InOrder();
	cout<<endl;
 return 0;
}

