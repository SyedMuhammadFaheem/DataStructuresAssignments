#include <iostream> //docs faheem
#include <vector>
using namespace std;
bool ShrinkableWord(string str,vector<string> s)
{


}
int main()
{
    int words;
    string str;
    vector<string> s;
    cout<<"Enter the string to check: ";
    cin>>str;
    cout<<"Enter the number of words: ";
    cin>>words;
    cout<<"Enter the words: ";
    string w;
    for(int i=0;i<words;i++)
    {
        cout<<"Word "<<i+1<<": ";
        cin>>w;
        s.push_back(w);
    }


   
   return 0;
}