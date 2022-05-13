#include <iostream>
#include <cmath>
using namespace std;
#define size 50
class HashTableEntry 
{
public:
    int k;
    int v;
    string type;
    HashTableEntry()
    {

    }
    HashTableEntry(int k, int v,string type) 
    {
        this->k= k;
        this->v = v;
        this->type=type;
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
    int DivisionHash(int k) 
    {
        return (k%size);
    }
    int MultiplicationHash(int k) 
    {
        double c=0.3;
        double intPart;
        double n=k*c;
        double frac=modf(n,&intPart);
        frac*=size;
        frac=floor(frac);
        return ((int)frac % size);
    }
    int MidSquareHash(int k) 
    {
        return (k*k)%size;
    }
    int FoldingHash(int k) 
    {
        return ((k%10)+((k/10)%10)+((k/100)%10)%size);
    }
    int RadixHash(int k) 
    {
        return ((k/10)%size);
    }
    int GenerateHashFunc(string type,int k)
    {
        int n;
        if(type=="DivisionHash")
        n=DivisionHash(k);
        else if(type=="MultiplicationHash")
        n=MultiplicationHash(k);
        else if(type=="MidSquareHash")
        n=MidSquareHash(k);
        else if(type=="FoldingHash")
        n=FoldingHash(k);
        else if(type=="RadixHash")
        n=RadixHash(k);
        else
        {
            cout<<"Invalid Hash Function Selected!"<<endl;
            return -1;
        }
        return n;
    }
    void Insert(int k, int v,string type) 
    {
        HashTableEntry* newValue=new HashTableEntry(k,v,type);
        int HashMapValue=GenerateHashFunc(type,k);
        int i=HashMapValue;
        while(i<size && t[i]!=NULL)
        {
            i++;
        }
        t[i]=newValue;
    }
    int SearchKey(int k,string type)
    {
        int HashMapValue=GenerateHashFunc(type,k);
        int i=HashMapValue;
        while(t[i]->k!=k && i<size)
        {
            i++;
        }
        if(i==size)
        return -1;
        return i;
    }
    void Remove(int k,string type) 
    {
        int HashMapValue=GenerateHashFunc(type,k);
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
        H1.Insert(i+(i/3),i,"DivisionHash");
    }
    //Traversing
    cout<<"Traversing the HashTable!"<<endl;
    H1.Traverse();
    //Searching
    cout<<"Searching for the key 46!"<<endl;
    int HashValue=H1.SearchKey(92,"DivisionHash");
    if(HashValue!=-1)
    cout<<"Key has been found at HashMap Value: "<<HashValue<<endl;
    else
    cout<<"Key has not been found!"<<endl;
    //Removing
    cout<<"Removing the key 92!"<<endl;
    H1.Remove(92,"DivisionHash");
    //Traversing after removing the key 92
    cout<<"Traversing after Removal!"<<endl;
    H1.Traverse();

//-----------------MultiplicationHash-------------------------
    HashMapTable H2;
    for(int i=69;i<=100;i++)
    {
        H2.Insert(i+(i/3),i,"MultiplicationHash");
    }
    //Traversing
    cout<<"Traversing the HashTable!"<<endl;
    H2.Traverse();
    //Searching
    cout<<"Searching for the key 46!"<<endl;
    HashValue=H2.SearchKey(92,"MultiplicationHash");
    if(HashValue!=-1)
    cout<<"Key has been found at HashMap Value: "<<HashValue<<endl;
    else
    cout<<"Key has not been found!"<<endl;
    //Removing
    cout<<"Removing the key 46!"<<endl;
    H2.Remove(92,"MultiplicationHash");
    //Traversing after removing the key 46
    cout<<"Traversing after Removal!"<<endl;
    H2.Traverse();

//-----------------MidSquareHash-------------------------
    HashMapTable H3;
    for(int i=69;i<=100;i++)
    {
        H3.Insert(i+(i/3),i,"MidSquareHash");
    }
    //Traversing
    cout<<"Traversing the HashTable!"<<endl;
    H3.Traverse();
    //Searching
    cout<<"Searching for the key 46!"<<endl;
    HashValue=H3.SearchKey(92,"MidSquareHash");
    if(HashValue!=-1)
    cout<<"Key has been found at HashMap Value: "<<HashValue<<endl;
    else
    cout<<"Key has not been found!"<<endl;
    //Removing
    cout<<"Removing the key 46!"<<endl;
    H3.Remove(92,"MidSquareHash");
    //Traversing after removing the key 46
    cout<<"Traversing after Removal!"<<endl;
    H3.Traverse();

//-----------------FoldingHash-------------------------
    HashMapTable H4;
    for(int i=69;i<=100;i++)
    {
        H4.Insert(i+(i/3),i,"FoldingHash");
    }
    //Traversing
    cout<<"Traversing the HashTable!"<<endl;
    H4.Traverse();
    //Searching
    cout<<"Searching for the key 46!"<<endl;
    HashValue=H4.SearchKey(92,"FoldingHash");
    if(HashValue!=-1)
    cout<<"Key has been found at HashMap Value: "<<HashValue<<endl;
    else
    cout<<"Key has not been found!"<<endl;
    //Removing
    cout<<"Removing the key 46!"<<endl;
    H4.Remove(92,"FoldingHash");
    //Traversing after removing the key 46
    cout<<"Traversing after Removal!"<<endl;
    H4.Traverse();

//-----------------RadixHash-------------------------
    HashMapTable H5;
    for(int i=69;i<=100;i++)
    {
        H5.Insert(i+(i/3),i,"RadixHash");
    }
    //Traversing
    cout<<"Traversing the HashTable!"<<endl;
    H5.Traverse();
    //Searching
    cout<<"Searching for the key 46!"<<endl;
    HashValue=H5.SearchKey(92,"RadixHash");
    if(HashValue!=-1)
    cout<<"Key has been found at HashMap Value: "<<HashValue<<endl;
    else
    cout<<"Key has not been found!"<<endl;
    //Removing
    cout<<"Removing the key 46!"<<endl;
    H5.Remove(92,"RadixHash");
    //Traversing after removing the key 46
    cout<<"Traversing after Removal!"<<endl;
    H5.Traverse();
    return 0;
}