#include <iostream>
using namespace std;
class Node
{
	public:
		int key;
		string name;
		Node* left;
		Node* right;
	Node()
	{
		key=0;
		name="";
		left=right=NULL;
	}
	Node(int key,string name)
	{
		this->key=key;
		this->name=name;
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
	Node* CreateNode(int key,string name)
	{
		Node* newNode=new Node(key,name);
		return newNode;
	}
	void InOrder(Node* root)
	{
		if(root)
		{
			InOrder(root->left);
			cout<<root->name<<" has the key "<<root->key<<endl;
			InOrder(root->right);
		}
	}
	void AddNode(int key,string name)
	{
		Node* newNode=CreateNode(key,name);
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
			if(newNode->key<root->key)
			root=root->left;	
			else
			root=root->right;
		}
		if(newNode->key<prev->key)
		{
			prev->left=newNode;
		}
		else
		prev->right=newNode;
		root=ptr;
	}
	void Traverse()
	{
		if(root==NULL)
		{
			cout<<"The BST is empty!"<<endl;
			return;
		}
		Node* temp=root;
		int i=1;
		while(temp)
		{
			cout<<temp->name<<endl;
			cout<<temp->left->name<<endl;
			cout<<temp->right->name<<endl;
			if(i%2!=0)
			temp=temp->left;
			else
			temp=temp->right;
			i++;
		}
	}
};
int main()
{
	BST T1;
	T1.AddNode(69,"Wahaj");
	T1.AddNode(420,"Faheem");
	T1.AddNode(121,"Sharma Jee");
	T1.AddNode(24,"Normie");
	T1.AddNode(125,"Monu");
	T1.InOrder(T1.root);

 return 0;
}

