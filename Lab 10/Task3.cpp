#include <iostream> //docs faheem
using namespace std;
#define TABLE_SIZE 50
class HashNode
{
    public:
        int key;
        int value;
    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
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
        bool check=false;
        for(int i=0;i<TABLE_SIZE;i++)
        {
            if(htable[i])
            {
                check=true;
                break;
            }
        }
        if(check)
        return false;
        return true;
    }
    int CountSize()
    {
        int count=0;
        for(int i=0;i<TABLE_SIZE;i++)
        {
            if(!htable[i])
            ++count;
        }
        return count;
    }
    int Search(int key)
    {
        int HashMapValue=HashFunc(key);
        int i=HashMapValue;
        while(htable[i]->key!=key && i<TABLE_SIZE)
        {
            i++;
        }
        if(i==TABLE_SIZE)
        return -1;
        return i;       
    }
    void Insert(int key,int value)
    {
        HashNode* newValue=new HashNode(key,value);
        int HashMapValue=HashFunc(key);
        int i=HashMapValue;
        while(i<TABLE_SIZE && htable[i]!=NULL)
        {
            i++;
        }
        htable[i]=newValue;
    }
    void Delete(int key)
    {
        int HashMapValue=HashFunc(key);
        int i=HashMapValue;
        if(i==-1)
        {
            cout<<"Element with the key "<<key<<" not found!"<<endl;
            return;
        }
        while(htable[i]->key!=key)
        {
            i++;
        }
        htable[i]=NULL;
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
            if(htable[i]!=NULL)
            cout<<htable[i]->key<<","<<htable[i]->value<<endl;
            else cout<<"NULL"<<endl;
        }
    }
};
int main()
{
    HashMap H1;
    //Checking if the HashTable is Empty
    if(H1.isEmpty())
    cout<<"The HashTable is Currently Empty! Please enter some values."<<endl;
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