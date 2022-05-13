#include <iostream> //docs faheem
using namespace std;
void BubbleSort(int* arr,int n)
{
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         if(arr[j]>arr[j+1])
         {
            arr[j]=arr[j]+arr[j+1];
            arr[j+1]=arr[j]-arr[j+1];
            arr[j]=arr[j]-arr[j+1];
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
   BubbleSort(arr,n);
   Display(arr,n);


   
   return 0;
}