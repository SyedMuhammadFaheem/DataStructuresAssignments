#include <iostream> //docs faheem
using namespace std;
void Input(int* arr,int size)
{
    cout<<"Enter the elements of the array: \n\n";
    for(int i=0;i<size;i++)
    {
        cout<<"Element ["<<i<<"]: ";
        cin>>arr[i];
    }
}
void Pattern(int* arr,int size)
{
    int* a=new int[size];
    int TempMax=-1,TempMin=-1,max=INT_MIN,min=INT_MAX,j=0;
    while(j<size)
    {

        for(int i=0;i<size;i++)
        {
            if(arr[i]==-1)
            continue;
            if(max<arr[i])
            {
                max=arr[i];
                TempMax=i;
            }
            if(min>arr[i])
            {
                min=arr[i];
                TempMin=i;
            }
            
        }
        a[j++]=arr[TempMax];
        arr[TempMax]=-1;
        a[j++]=arr[TempMin];
        arr[TempMin]=-1;
        max=INT_MIN;
        min=INT_MAX;
    }
    cout<<"The elements of the array after converting into the specified pattern are: \n";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int* arr=new int[size];
    Input(arr,size);
    Pattern(arr,size);
   
   return 0;
}