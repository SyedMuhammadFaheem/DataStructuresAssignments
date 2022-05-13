#include <iostream>
using namespace std;
#define size 50
class HashTableEntry 

{
public:
    int k;
    int v;
    HashTableEntry()
    {

    }
    HashTableEntry(int k, int v) 
    {
        this->k= k;
        this->v = v;
    }
};
class HashMapTable {
private:
    HashTableEntry **t;
public:
    HashMapTable()
    {
        t=new HashTableEntry*[size];
        for(int i=0;i<size;i++)
        {
            t[i]=NULL;
        }
    }
    int HashFunc(int k) 
    {
        return (k%size);
    }
    void Insert(int k, int v) 
    {
        HashTableEntry* newValue=new HashTableEntry(k,v);
        int HashMapValue=HashFunc(k);
        int i=HashMapValue;
        while(i<size && t[i]!=NULL)
        {
            i++;
        }
        t[i]=newValue;
    }
    int SearchKey(int k)
    {
        int HashMapValue=HashFunc(k);
        int i=HashMapValue;
        while(t[i]->k!=k && i<size)
        {
            i++;
        }
        if(i==size)
        return -1;
        return i;
    }
    void Remove(int k) 
    {
        int HashMapValue=HashFunc(k);
        int i=HashMapValue;
        if(i==-1)
        {
            cout<<"Element with the key "<<k<<" not found!"<<endl;
            return;
        }
        while(t[i]->k!=k)
        {
            i++;
        }
        t[i]=NULL;
    }
    ~HashMapTable() 
    {
        delete [] t;
        t=NULL;
    }
    void Traverse()
    {
        for(int i=0;i<size;i++)
        {
            if(t[i]!=NULL)
            cout<<t[i]->k<<","<<t[i]->v<<endl;
            else cout<<"NULL"<<endl;
        }
    }
};
int main()
{
    HashMapTable H1;
    for(int i=69;i<=100;i++)
    {
        H1.Insert(i+(i/3),i);
    }
    //Traversing
    cout<<"Traversing the HashTable!"<<endl;
    H1.Traverse();
    //Searching
    cout<<"Searching for the key 46!"<<endl;
    int HashValue=H1.SearchKey(92);
    if(HashValue!=-1)
    cout<<"Key has been found at HashMap Value: "<<HashValue<<endl;
    else
    cout<<"Key has not been found!"<<endl;
    //Removing
    cout<<"Removing the key 46!"<<endl;
    H1.Remove(92);
    //Traversing after removing the key 46
    cout<<"Traversing after Removal!"<<endl;
    H1.Traverse();
    return 0;
}