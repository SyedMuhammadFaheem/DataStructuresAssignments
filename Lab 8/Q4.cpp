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
    Node* InOrderPredecessor(Node* root)
    {
        root=root->left;
        while(root->right)
        root=root->right;
        return root;

    }
    Node* InOrderSuccessor(Node* root)
    {
        root=root->right;
        while(root->left)
        root=root->left;
        return root;
        
    }
    Node* DeleteNodes(Node* root,int value)
    {
            if(!root)	// only one node and that is the root
            return root;
            if(!root->left && !root->right) // leaf node
            {
                root=NULL;
                return root;
            }
            if(root->data<value)  // if the node which is going to be deleted has a value greater than the current node
            root->right=DeleteNodes(root->right,value);
            else if(root->data>value)	// if the node which is going to be deleted has a value lesser than the current node
            root->left=DeleteNodes(root->left,value);
            else	// if the node with value is found
            {
                if(root->left) // if the node which is going to be deleted is the left child
                {
                    Node* Pre=InOrderPredecessor(root);
                    root->data=Pre->data;
                    root->left=DeleteNodes(root->left,Pre->data);
                }
                else	// if the node which is going to be deleted is the right child
                {
                    Node* Post=InOrderSuccessor(root);
                    root->data=Post->data;
                    root->right=DeleteNodes(root->right,Post->data);
                }

            }
            return root;

    }
};
int main()
{
	BST T1;
//	15, 10, 20, 8, 12, 16, 25
	T1.Insert(15);
    T1.Insert(10);
	T1.Insert(20);
    T1.Insert(8);
	T1.Insert(12);
    T1.Insert(16);
    T1.Insert(25);
    T1.InOrder(T1.root);
	int n1,n2;
    cout<<"Enter the range of values: ";
    cin>>n1>>n2;
    while(n1<=n2)
    {
        T1.root=T1.DeleteNodes(T1.root,n1);
        ++n1;
    }
    cout<<"\nThe InOrder Traversal of the values in the BST is: ";
	T1.InOrder(T1.root);
	cout<<endl;
 return 0;
}

