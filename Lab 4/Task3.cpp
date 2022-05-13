#include <iostream> //docs faheem
using namespace std;
void InsertionSort(int* arr,int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]<arr[j])
         {
            arr[i]=arr[i]+arr[j];
            arr[j]=arr[i]-arr[j];
            arr[i]=arr[i]-arr[j];
         }

        }
    }

}
void Input(int* arr,int n)
{
   cout<<"Enter the elements of the array: ";
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
   }
}
void Display(int* arr,int n)
{
    cout<<"The elements of the array are: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int* arr=new int[n];
    Input(arr,n);
    InsertionSort(arr,n);
    Display(arr,n);
   
   return 0;
}