#include <iostream>     //docs faheem
#include <string>
using namespace std;
class Node
{
    public:
    int coeff;
    char var;
    int power;
    Node* next;
    Node()
    {
        coeff=0; 
        var=' ';
        power=0;
        next=NULL;
    }
    Node(int coeff,char var,int power)
    {
        this->coeff=coeff; 
        this->var=var;
        this->power=power;
        next=NULL;
    }
    
};
class LinkedList
{
    public:
    static int count;
    Node* head;
    LinkedList()
    {
        head=NULL;
    }
    Node* CreateNode(int coeff,char var,int power)
    {
        Node* newNode=new Node(coeff,var,power);
        return newNode;
    }
    bool isEmpty()
    {
        if(head==NULL)
        return true;
        return false;
    }
    void Append(int coeff,char var,int power)
    {
        Node* n=CreateNode(coeff,var,power);
        if(isEmpty())
        {
            head=n;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        
    }
    void AppendL3(Node* temp,Node* temp1)
    {
        count++;
        Node* n=new Node();
        n->coeff=(temp->coeff+temp1->coeff);
        n->var=temp->var;
        n->power=temp->power;
        if(isEmpty())
        {
            head=n;
            return;
        }
        Node* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=n;
    }
    void AppendL3Overload(Node* temp)
    {
        count++;
        Node* n=new Node();
        n->coeff=temp->coeff;
        n->var=temp->var;
        n->power=temp->power;
        if(isEmpty())
        {
            head=n;
            return;
        }
        Node* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=n;
    }
    void AddSum(LinkedList L1,LinkedList L2)
    {
        bool check=false;
        if(L1.isEmpty() && L2.isEmpty())
        {
            return;
        }
        Node* temp=L1.head;
        Node* temp1;
        while(temp)
        {
            temp1=L2.head;
            while(temp1)
            {
                if((temp->power==temp1->power) && (temp->var==temp1->var))
                {
                    check=true;
                    AppendL3(temp,temp1);
                }
                temp1=temp1->next;
            }
            if(!check)
            {
                AppendL3Overload(temp);
            }
            check=false;
            temp=temp->next;
        }
        temp=head;
        temp1=L2.head;
        while(temp1)
        {
            if(temp1->var!=temp->var)
            AppendL3Overload(temp1);
            temp=temp->next;
            temp1=temp1->next;
        }

    }
    void Sort()
    {
        if(isEmpty())
        return;
        Node* temp=head;
        while(temp)
        {
            Node* temp1=temp->next;
            while(temp1)
            {
                if(temp->power>temp1->power)
                {
                    int hold1=temp->coeff;
                    temp->coeff=temp1->coeff;
                    temp1->coeff=hold1;
                    char hold2=temp->var;
                    temp->var=temp1->var;
                    temp1->var=hold2;
                    int hold3=temp->power;
                    temp->power=temp1->power;
                    temp1->power=hold3;
                    
                }
                if(temp->var>temp1->var)
                {
                    int hold1=temp->coeff;
                    temp->coeff=temp1->coeff;
                    temp1->coeff=hold1;
                    char hold2=temp->var;
                    temp->var=temp1->var;
                    temp1->var=hold2;
                    int hold3=temp->power;
                    temp->power=temp1->power;
                    temp1->power=hold3;
                }
                temp1=temp1->next;
            }
            temp=temp->next;
        }
    }
    void Traverse()
    {
        if(isEmpty())
        return;
        cout<<count<<endl;
        Node* temp=head;
        while(temp)
        {
            cout<<temp->coeff<<" "<<temp->var<<" "<<temp->power<<endl;
            temp=temp->next;
        }
    }
    
    
};
int LinkedList ::count=0;
int main() {
	// use standard input and output (no file i/o required)
	// TODO: Your solution here
	LinkedList L1;
	LinkedList L2;
    LinkedList L3;
	int n;
	cin>>n;
    int coeff,power;
    char var;
	while(n)
	{
	    cin>>coeff;
        cin>>var;
        cin>>power;
	    L1.Append(coeff,var,power);
	    --n;
	}
	cin>>n;
	while(n)
	{
        cin>>coeff;
        cin>>var;
        cin>>power;
	    L2.Append(coeff,var,power);
	    --n;	
    }
    L3.AddSum(L1,L2);
    L3.Sort();
    L3.Traverse();
	return 0; // always return 0 from here
}
