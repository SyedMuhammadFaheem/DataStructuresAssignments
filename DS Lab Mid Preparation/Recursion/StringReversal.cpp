#include <iostream> //docs faheem
using namespace std;
void StringReversal(string &s,int start)
{
    if(start>s.length()-1)
    return;
    else
    {
        StringReversal(s,start+1);
        cout<<s[start];
    }
}
int main()
{
    string str;
    cout<<"Enter the string you want to print in reverse order: ";
    cin>>str;
    cout<<"The String in reversed order is: ";
    StringReversal(str,0);


   
   return 0;
}