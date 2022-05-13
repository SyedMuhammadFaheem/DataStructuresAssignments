#include <iostream> //docs faheem
using namespace std;
int Toys(int* arr,int n,int k)
{
    int count=0,sum=0;
    for(int i=0;i<n;i++)
    {
        if(sum>=k)
        break;
        if(arr[i]<=k)
        {
            sum+=arr[i];
            count++;
        }
        else continue;
    }
    return count;
}
void Input(int* arr,int n)
{
   cout<<"Enter the elements of the array: ";
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
   }
}
int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int* arr=new int[n];
    int k;
    cout<<"Enter the amount: ";
    cin>>k;
    Input(arr,n);
    cout<<"The maximum number of toys which can be bought are: "<<Toys(arr,n,k);
   
   return 0;
}