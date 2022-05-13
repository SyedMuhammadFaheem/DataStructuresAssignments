#include <iostream> //docs faheem
using namespace std;
bool StringSubsequence(string str1,string str2)
{
    static int i=0,j=0,count=0;
    if(j<str1.length())
    {
        if(str2[i]==str1[j])
        {
            ++count;
            ++i;
            ++j;
            StringSubsequence(str1,str2);
        }
        ++j;
        StringSubsequence(str1,str2);
    }
    if(count==str2.length())
    return true;
    else
    return false;

}
int main()
{
    string str1,str2;
    cout<<"Enter the string: ";
    cin>>str1;
    cout<<"Enter the substring: ";
    cin>>str2;
    if(StringSubsequence(str1,str2))
    cout<<"The Substring is a part of the string sequence!"<<endl;
    else
    cout<<"The Substring is not a part of the string sequence!"<<endl;
   return 0;
}