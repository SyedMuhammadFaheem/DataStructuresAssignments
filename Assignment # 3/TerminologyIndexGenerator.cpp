#include <iostream> //docs faheem
#include <string>
#include <iomanip>
using namespace std;
struct Sentences
{
    string linenum;
    string sentence;

};
void Sort(struct Sentences* words,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(words[i].sentence>words[j].sentence)
            {
                string temp=words[i].linenum;
                words[i].linenum=words[j].linenum;
                words[j].linenum=temp;

                temp=words[i].sentence;
                words[i].sentence=words[j].sentence;
                words[j].sentence=temp;
            }
        }
    }
}
class Node
{
    public:
    struct Sentences data;
    string serial;
    Node* left;
    Node* right;
    Node()
    {
        this->data.linenum="\0";
        this->data.sentence="\0";
        this->left=this->right=NULL;
    }
    Node(string linenum,string Sentence)
    {
        this->data.linenum=linenum;
        this->data.sentence=Sentence;
        this->left=this->right=NULL;
    }    
    Node(string serial,string linenum,string Sentence)
    {
        this->serial=serial;
        this->data.linenum=linenum;
        this->data.sentence=Sentence;
        this->left=this->right=NULL;
    }
};
class LLNode
{
    public:
    string data;
    LLNode* next;
    LLNode()
    {
        data=" ";
        this->next=NULL;
    }
    LLNode(string data)
    {
        this->data=data;
        this->next=NULL;
    }

};
class LinkedList
{
    public:
    LLNode* root;
    LinkedList()
    {
        root=NULL;
    }
    void Insertion(string data)
    {
        LLNode* newNode= new LLNode(data);
        if(!root)
        {
            root=newNode;
            return;
        }
        LLNode* temp=root;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newNode;

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
    void Insertion(string linenum,string Sentence)
    {
        Node* newNode= new Node(linenum,Sentence);
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
            if(newNode->data.linenum>temp->data.linenum)
            root=root->right;
            else if(newNode->data.linenum<temp->data.linenum)
            root=root->left;
            else 
            {
                root=temp;
                return;
            }
        }
        if(newNode->data.linenum>temp->data.linenum)
        prev->right=newNode;
        else
        prev->left=newNode;
        root=temp;
    }
    void InsertResult(string line,string sentence)
    {
        string serial=sentence;
        Node* newNode= new Node(serial,line,sentence);
        if(!root)
        {
            root=newNode;
            return;
        }
        Node* prev=NULL;
        Node* temp=root;
        while(root)
        {
            if(root->data.sentence==sentence )
            {
                root->data.linenum+=" ";
                root->data.linenum+=line;
                root=temp;
                return;
            }
            prev=root;
            if(newNode->serial>temp->serial)
            root=root->right;
            else if(newNode->serial<temp->serial)
            root=root->left;
        }
        if(newNode->serial>temp->serial)
        prev->right=newNode;
        else
        prev->left=newNode;
        root=temp;
    }
    void InOrder(Node* root, struct Sentences* r)
    {
    	static int var=0;
    	if(root)
    	{
	        InOrder(root->left,r);
            if(root->data.linenum=="0")
            {
	            r[var].linenum="0";
	         	r[var].sentence=root->data.sentence;
	          	++var;
			}
            else
            {
	         	r[var].linenum=root->data.linenum;
	         	r[var].sentence=root->data.sentence;
	          	++var;
            	
			}
	        InOrder(root->right,r);
		}
    }
    void Search(BST B1,LinkedList L1,int size1,int size2)
    {
    	struct Sentences r[size1];
        int var=0;
        BST B2;
        struct Sentences t1[size2];
        B1.getBSTData(t1,B1.root);
        LLNode* n=L1.root;
        for(int i=0;i<size1;i++)        // for all the words
        {
            string temp=n->data;
            int count=0;
            for(int j=0;j<size2;j++)        // for a specific word to get compared with a sentence
            {
                bool check=false;
                string v=t1[j].sentence;
                int index1=0,index2=0;
                for(int k=0;k<v.size();k++)     // to compare a word index by index with sentence 
                {
                    if(v[k]==temp[index1])
                    {
                        index2=k;
                        while(index1<temp.size())
                        {
                            if(v[index2]!=temp[index1])
                            {
                                check=false;
                                index1=0;
                                break;
                            }
                            index1++;
                            index2++;
                            check=true;
                        }
                    }
                    if(check)
                    {
                        B2.InsertResult(t1[j].linenum,temp);
                        ++count;
                    }
                    check=false;
                }
            }
            if(count==0)
            {
                B2.InsertResult("0",temp);
            }
            count=0;
            n=n->next;
        }
        B2.InOrder(B2.root,r);
        Sort(r,size1);
        for(int i=0;i<size1;i++)
        {
            if(r[i].linenum=="0")
            cout<<r[i].sentence<<endl;
            else
            cout<<r[i].sentence<<" "<<r[i].linenum<<endl;

        }

    }
    void getBSTData(struct Sentences* s,Node* root)
    {
        static int i=0;
        if(root)
    	{
	        getBSTData(s,root->left);
	        s[i]=root->data;
            i++;
	        getBSTData(s,root->right);
		}

    }
};
int main()
{
    BST B1;
    LinkedList L1;
    int size1,size2;
    cin>>size1;
    string word;
    for(int i=0;i<size1;i++)
    {
    	cin>>ws;
        getline(cin,word);
        L1.Insertion(word);
    }
    cin>>ws;
    cin>>size2;
    struct Sentences s1[500];
    for(int i=0;i<size2;i++)
    {
        cin>>ws;
        cin>>s1[i].linenum;
        if(s1[i].linenum=="v")
        {
            B1.Insertion(s1[i].linenum,"\0");
            continue;    
        }
        getline(cin,s1[i].sentence);
        B1.Insertion(s1[i].linenum,s1[i].sentence);
    }
    B1.Search(B1,L1,size1,size2);
   
   return 0;
}