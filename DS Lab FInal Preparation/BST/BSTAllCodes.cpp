#include <iostream>
#include <Stack>
#include <climits>
using namespace std;
class Node
{
	public:
	int data;
	Node* left;
	Node* right;
	Node()
	{
		this->right=this->left=NULL;
	}
  	Node(int data)
	{
		this->data=data;
		this->right=this->left=NULL;
	}
};
class BST
{
	public:
	Node* root;
	BST()
	{
		this->root=NULL;
	}
    int Depth(Node* root,Node* find)
    {
        static int count=0;
        if(!root)
        return count;
        if(root->data==find->data)
        return count;
        if(root->data>find->data)
        Depth(root->left,find);
        else
        Depth(root->right,find);

    }
    int SizeRecursive(Node* root)
    {
        static int count=0;
        if(root)
        {
            SizeRecursive(root->left);
            ++count;
            SizeRecursive(root->right);
        }
        return count;
    }
    int SizeIterative(Node* root)
    {
        int count=0;
        if(!root)
        return 0;
        stack<Node*> temp;
        temp.push(root);
        while(!temp.empty())
        {
            Node* hold=temp.top();
            temp.pop();
            ++count;
            if(hold->right)
            temp.push(hold->right);
            else
            temp.push(hold->left);
        }
        return count;
    }
    int HeightRecursive(Node* root)
    {
        if(root)
        {
            int LeftHeight=HeightRecursive(root->left);
            int RightHeight=HeightRecursive(root->right);
            if(LeftHeight>RightHeight)
            return LeftHeight+1;
            return RightHeight+1;

        }
        return -1;
    }
    int HeightIterative(Node* root)
    {
        int countRight=0,countLeft=0,max1=INT_MIN,max2=INT_MIN;
        Node* temp=root->left;
        while(temp)
        {
            Node* hold=temp->right;
            while(hold)
            {
                countRight++;
                hold=hold->right;
            }
            countLeft++;
            temp=temp->left;
        }
        if(countLeft>countRight)
        max1=countLeft;
        else
        max1=countRight;
        countLeft=countRight=0;
        temp=root->right;
        while(temp)
        {
            Node* hold=temp->left;
            while(hold)
            {
                countLeft++;
                hold=hold->left;
            }
            countRight++;
            temp=temp->right;
        }
        if(countLeft>countRight)
        max2=countLeft;
        else
        max2=countRight;
        if(max1>max2)
        return max1;
        return max2;
    }
    int LevelRecursive(Node* root)
    {
        return HeightRecursive(root)+1;
    }
    int LevelIterative(Node* root)
    {
        int countRight=0,countLeft=0,max1=0,max2=0;
        Node* temp=root->left;
        while(temp)
        {
            Node* hold=temp->right;
            while(hold)
            {
                countRight++;
                hold=hold->right;
            }
            countLeft++;
            temp=temp->left;
        }
        if(countLeft>countRight)
        max1=countLeft;
        else
        max1=countRight;
        countLeft=countRight=0;
        temp=root->right;
        while(temp)
        {
            Node* hold=temp->left;
            while(hold)
            {
                countLeft++;
                hold=hold->left;
            }
            countRight++;
            temp=temp->right;
        }
        if(countLeft>countRight)
        max2=countLeft;
        else
        max2=countRight;
        if(max1>max2)
        return max1+1;
        return max2+1;
    }
    int countFullNodes(Node* root)
    {
        int h=HeightRecursive(root);
        int count=0;
        for(int i=0;i<h;i++)
        {
            count=GetLevel(root,i)-count;
        }
        return count;
    }
    int GetLevel(Node* root,int level)
    {
        static int CountFull=0;
        if(!root)
        return CountFull;
        if(level==0)
        {
            if(root->left && root->right)
            ++CountFull;
        }
        else if(level>0)
        {
            GetLevel(root->left,level-1);
            GetLevel(root->left,level-1);
        }
        
    }	
    int countLeafNodes(Node* root)
    {
        int h=HeightRecursive(root);
        int count=0;
        for(int i=0;i<h;i++)
        {
            count=GetLevelLeaf(root,i)-count;
        }
        return count;
    }
    int GetLevelLeaf(Node* root,int level)
    {
        static int CountLeaf=0;
        if(!root)
        return CountLeaf;
        if(level==0)
        {
            if(!root->left && !root->right)
            ++CountLeaf;
        }
        else if(level>0)
        {
            GetLevelLeaf(root->left,level-1);
            GetLevelLeaf(root->left,level-1);
        }
    }

    int countNeitherNodes(Node* root)
    {
        int h=HeightRecursive(root);
        int count=0;
        for(int i=0;i<h+1;i++)
        {
            count=GetLevelNeither(root,i);
        }
        return count;
    }
    int GetLevelNeither(Node* root,int level)
    {
        static int CountNeither=0;
        if(!root)
        return CountNeither;
        if(level==0)
        {
            cout<<"Data = "<<root->data<<endl;
            if(!(root->left) && root->right)
            ++CountNeither;
            if(root->left && !(root->right))
            ++CountNeither;
        }
        else if(level>0)
        {
            GetLevelNeither(root->left,level-1);
            GetLevelNeither(root->right,level-1);
        }
        return CountNeither;
    }
    // bool CheckComplete(Node* root)
    // {
    //     int h=HeightRecursive(root);
    //     int count=0;
    //     for(int i=0;i<h;i++)
    //     {
    //         count=GetLevelNeither(root,0)-count;
    //     }
    // }

    void Insert(int data)
    {
        Node* newNode= new Node(data);
        if(!root)
        {
            root=newNode;
            return;
        }
        Node* temp=root;
        Node* hold;
        while(root)
        {
            hold=root;
            if(root->data>newNode->data)
            root=root->left;
            else if(root->data>newNode->data)
            root=root->right;
            else 
            {
                root=temp;
                return;
            }
        }
        if(hold->data>newNode->data)
        hold->left=newNode;
        else
        hold->right=newNode;
        root=temp;

    }
};
int main()
{
	BST B1;
    B1.Insert(5);
    B1.Insert(4);
    B1.Insert(3);
    B1.Insert(2);
    B1.Insert(1);
    B1.Insert(10);
    B1.Insert(11);
    cout<<B1.countNeitherNodes(B1.root);

	return 0;
}
