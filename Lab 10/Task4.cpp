#include <iostream> //docs faheem
using namespace std;
#define TABLE_SIZE 50
class HashNode
{
    public:
        int key;
        int value;
        HashNode* next;
    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};
class HashMap
{
    private:
        HashNode** htable;
    public:
    HashMap()
    {
        htable = new HashNode*[TABLE_SIZE];
        for (int i = 0; i<TABLE_SIZE; i++)
        htable[i] = NULL;
    }
    int HashFunc(int k) 
    {
        return (k%TABLE_SIZE);
    }
    bool isEmpty()
    {
        for(int i=0;i<TABLE_SIZE;i++)
        {
            if(htable[i])
            {
                return false;
            }
        }
		return true;
    }
    int CountSize()
    {
        int count=0;
        for(int i=0;i<TABLE_SIZE;i++)
        {
            if(htable[i]!=NULL)
            {
                ++count;
                if(htable[i]->next)
                {
                    HashNode* temp=htable[i]->next;
                    while(temp)
                    {
                        ++count;
                        temp=temp->next;
                    }
                }
            }
        }
        return count;
    }
    int Search(int key)
    {
        int HashMapValue=HashFunc(key);
        int i=HashMapValue;
        if(htable[i]->key==key)
        return i;
        else
        {
            int count=1;
            HashNode* temp=htable[i]->next;
            while(temp->key!=key && temp)
            {
                ++count;
                temp=temp->next;
            }
            if(temp)
            {
                cout<<"The Searched key was found at HashMap Value "<<i<<" with a Chaining of "<<count<<" Nodes!"<<endl;
                return i;
            }
            else return -1;
        } 
        return -1;       
    }
    void Insert(int key,int value)
    {
        
        HashNode* newValue= new HashNode(key,value);
        int HashMapValue=HashFunc(key);
        int i=HashMapValue;
        if(htable[i]!=NULL)
        {
            HashNode* temp=htable[i]->next;
            if(!htable[i]->next)
            htable[i]->next=newValue;
            else
            {
                while(temp->next)
                {
                    temp=temp->next;
                }
                temp->next=newValue;
            }
        }
        else
        htable[i]=newValue;
        cout<<"The Hash Node with pair "<<key<<", "<<value<<" has been inserted successfully!"<<endl;
    }
    void Delete(int key)
    {
        int HashMapValue=HashFunc(key);
        int i=HashMapValue;
        HashNode* temp=htable[i]->next;
        if(htable[i]->key==key)
        {
            htable[i]=NULL;
        }
        else
        {
            while(temp->key!=key)
            {
                temp=temp->next;
            }
            HashNode* freeNode=temp;
            temp=temp->next;
            freeNode=NULL;
        }
    }
    ~HashMap() 
    {
        delete [] htable;
        htable=NULL;
    }
    void Traverse()
    {
        for(int i=0;i<TABLE_SIZE;i++)
        {
            if(htable[i])
            {
                cout<<htable[i]->key<<","<<htable[i]->value;
                if(htable[i]->next)
                {
                    HashNode* temp= htable[i]->next;
                    while(temp)
                    {
                        cout<<" -> "<<temp->key<<","<<temp->value;
                        temp=temp->next;
                    }
                    cout<<" -> NULL"<<endl;
                }
                else
                cout<<" -> NULL"<<endl;
            }
            else cout<<"NULL"<<endl;
        }
    }
};
int main()
{
    HashMap H1;
    cout<<"hello";
//    Checking if the HashTable is Empty
     if(H1.isEmpty())
     cout<<"The HashTable is Currently Empty! Please enter some values."<<endl;
     else cout<<"The Hash Table is not empty!"<<endl;
	 for(int i=69;i<=100;i++)
     {
         H1.Insert(i+(i/3),i);
     }
    //Counting the size of the HashTable
    cout<<"The Count of the elements in the HashTable is: "<<H1.CountSize()<<endl;
    //Traversing
    cout<<"Traversing the HashTable!"<<endl;
    H1.Traverse();
    //Searching
    cout<<"Searching for the key 46!"<<endl;
    int HashValue=H1.Search(92);
    if(HashValue!=-1)
    cout<<"Key has been found at HashMap Value: "<<HashValue<<endl;
    else
    cout<<"Key has not been found!"<<endl;
    //Removing
    cout<<"Removing the key 46!"<<endl;
    H1.Delete(92);
    //Traversing after removing the key 46
    cout<<"Traversing after Removal!"<<endl;
    H1.Traverse();

   
   return 0;
}