#include <iostream> //docs faheem
using namespace std;
void Input(int* arr,int n)
{
   cout<<"Enter the elements of the array: ";
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
   }
}
void SubArraySort(int* arr,int n)
{
    int low,high,check=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1] && i+1<n)
        {
            low=i;
            for(int j=low+2;j<n;j++)
            {
                if(arr[j]<arr[j+1] && j+1<n)
                {
                    check=1;
                    high=j+1;
                    break;
                }   
            }
            if(check==1)
            break;

        }
    }
    for(int i=low;i<high;i++)
    {
        for(int j=i+1;j<high;j++)
        {
            if(arr[i]>arr[j])
            {
                arr[i]=arr[i]+arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]=arr[i]-arr[j];
            }
        }
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
    SubArraySort(arr,n);
    Display(arr,n);
   
   return 0;
}