#include <iostream>
#include <string>
using namespace std;
class Node
{
	public:
		int key;
		Node* left;
		Node* right;
	Node()
	{
		key=0;
		left=right=NULL;
	}
	Node(int data)
	{
		this->key=data;
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
	Node* CreateNode(int key)
	{
		Node* newNode=new Node(key);
		return newNode;
	}
	void InOrder(Node* root)
	{
		if(root)
		{
			InOrder(root->left);
			cout<<root->key<<" ";
			InOrder(root->right);
		}
	}
	void Insert(int key)
	{
		Node* newNode=CreateNode(key);
		if(root==NULL)
		{
			root=newNode;
			return;
		}
		Node* prev=NULL;
		Node* ptr=root;
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
};
int main()
{
	BST T1;
	string str,temp;
	fflush(stdin);
	cout<<"Enter the values as a string: ";
	getline(cin,str);
	int i=0;
	while(true)
	{
		if(str[i]==',' || str[i]=='\0')
		{
			T1.Insert(stoi(temp));
			temp="";
			if(str[i]=='\0' && str.length())
			break;

		}
		else if(str[i]>=48 && str[i]<=57)
		{
			temp+=str[i];
		}
		i++;
	}
	cout<<"\n\nThe InOrder Traversal of the values of the BST is: ";
	T1.InOrder(T1.root);
 return 0;
}

