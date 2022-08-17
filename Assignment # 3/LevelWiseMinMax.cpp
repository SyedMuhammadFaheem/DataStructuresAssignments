#include <iostream> //docs faheem
#include <climits>
#include <vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node()
    {
        this->data=0;
        this->left=this->right=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->left=this->right=NULL;
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
    void Insertion(int data)
    {
        Node* newNode= new Node(data);
        if(!root)
        {
            root=newNode;
            return;
        }
        Node* prev=NULL;
        Node* temp=root;
        while(root)
        {
            prev=root;
            if(newNode->data>root->data)
            root=root->right;
            else if(newNode->data<root->data)
            root=root->left;
            else 
            {
                root=temp;
                return;
            }

        }
        if(newNode->data>prev->data)
        prev->right=newNode;
        else
        prev->left=newNode;
        root=temp;
    }
    int getHeight()
    {
        Node* temp=root;
        int countRight=0,countLeft=0;
        int max1=INT_MIN,max2=INT_MIN;
        if(!root)
        return -1;
        while(temp)
        {
            Node* hold=temp->right;
            while(hold)
            {
                countRight++;
                hold=hold->right;
            }
            countLeft++;
            if(countLeft>countRight)
            max1=countLeft;
            else
            max1=countRight;
            temp=temp->left;
        }
        temp=root;
        countRight=0,countLeft=0;
        while(temp)
        {
            Node* hold=temp->left;
            while(hold)
            {
                countLeft++;
                hold=hold->left;
            }
            countRight++;
            if(countLeft>countRight)
            max2=countLeft;
            else
            max2=countRight;
            temp=temp->right;
        }
        if(max1>max2)
        return max1;
        return max2;
    }
    void GetMinMax()
    {   
        int flag,flag1;
        int min=INT_MAX,max=INT_MIN;
        vector<int> v1;
        int h=getHeight();
        for(int i=1;i<=h;i++)
        {
            getCurrentLevel(root,i,&v1);
            for(int j=0;j<v1.size();j++)
            {
                if(min>v1[j])
                {
                    min=v1[j];	
                    flag=1;
				}
                
                if(max<v1[j])
                {
                    max=v1[j];
                    flag1=1;
				}
                
            }
            if(flag==1 && flag1==1)
            cout<<min<<" "<<max<<endl;
            flag=flag1=0;
            min=INT_MAX;
            max=INT_MIN;
            v1.erase(v1.begin(),v1.end());
        }

    }
    
    vector<int>* getCurrentLevel(Node* root,int level,vector<int>* v1)
    {
        if(!root)
        return v1;
        if(level==1)
        {
            v1->push_back(root->data);
        }
        else if(level>1)
        {
            getCurrentLevel(root->left,level-1,v1);
            getCurrentLevel(root->right,level-1,v1);
        }
        return v1;
    }

};
int main()
{
    BST B1;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        B1.Insertion(data);
    }
    
    B1.GetMinMax();
   
   return 0;
}