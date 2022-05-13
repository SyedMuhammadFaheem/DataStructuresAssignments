#include <iostream> //docs faheem
using namespace std;
void Input(int* arr,int size)
{
    cout<<"Enter the elements of the array: \n\n";
    for(int i=0;i<size;i++)
    {
        cout<<"Element ["<<i<<"]: ";
        cin>>*(arr+i);
    }

}
void AscendingOrder(int* arr,int size)
{
    int min=INT_MAX,max=INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(min>arr[i])
        min=arr[i];
        if(max<arr[i])
        max=arr[i];
    }
    cout<<"The elements of the array in Ascending Order are: "<<endl;
    while(min<=max)
    {
        for(int i=0;i<size;i++)
        {
            if(min==arr[i])
            cout<<arr[i]<<" ";
        }
        ++min;
    }


}
void DescendingOrder(int* arr,int size)
{
    int min=INT_MAX,max=INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(min>arr[i])
        min=arr[i];
        if(max<arr[i])
        max=arr[i];
    }
    cout<<"\n\nThe elements of the array in Descending Order are: "<<endl;
    while(min<=max)
    {
        for(int i=0;i<size;i++)
        {
            if(max==arr[i])
            cout<<arr[i]<<" ";
        }
        --max;
    }

}
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int* arr=new int[size];
    Input(arr,size);
    AscendingOrder(arr,size);
    DescendingOrder(arr,size);
   
   return 0;
}