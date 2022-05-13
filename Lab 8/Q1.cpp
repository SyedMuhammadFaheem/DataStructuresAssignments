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
    bool autoGrader()
	{
		Node* temp=root;
		while(temp)
		{
			if(temp->right && temp->right->right)
			{
				if(temp->data<temp->right->data || temp->data>temp->right->right->data)
				return false;
			}
			temp=temp->right;
		}
		return true;
	}
	void Insert(int data)
	{
        Node* newNode=CreateNode(data);
		if(root==NULL)
		{
			root=newNode;
			return;
		}
		Node* temp=root;
		while(temp->right)
		{
			temp=temp->right;
		}
		temp->right=newNode;
		newNode->left=temp;
	}
};
int main()
{
	int n;
	cout<<"Enter the number of assignments of the students: ";
	cin>>n;
	BST T1[n];
	int i=0;
	while(n)
	{
		int num;
		cout<<"Enter the number of values you want to enter in your BST: ";
		cin>>num;
		int* values=new int[num];
		for(int j=0;j<num;j++)
		{
			cin>>values[j];
		}
		for(int j=0;j<num;j++)
		{
			T1[i].Insert(values[j]);

		}
		delete values;
		if(T1[i].autoGrader())
		cout<<"10 Points have been assigned to Student "<<i+1<<endl;
		else
		cout<<"Zero (0) Points have been assigned to Student "<<i+1<<endl;
		i++;
		--n;
	}
 return 0;
}

