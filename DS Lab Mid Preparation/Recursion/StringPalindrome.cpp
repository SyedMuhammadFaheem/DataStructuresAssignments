#include <iostream> //docs faheem
using namespace std;
bool StringPalindrome(string s,int start,int end)
{
    if(start>end)
    return true;
    if(s[start]==s[end])
    StringPalindrome(s,start+1,end-1);
    else
    return false;
    
}
int main()
{
    string str;
    cout<<"Enter the string to check for Palindrome: ";
    cin>>str;
    if(StringPalindrome(str,0,str.length()-1))
    cout<<"The Entered String is a Palindrome!"<<endl;
    else
    cout<<"The Entered String is not a Palindrome!"<<endl;
   
   return 0;
}