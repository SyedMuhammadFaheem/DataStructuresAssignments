#include <bits/stdc++.h>
using namespace std;
void Input(int *arr,int size)
{
	cout<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"Element "<<i<<": ";
		cin>>arr[i];
	}
}
void MinMax(int *arr,int size)
{
	int min=-999,max=arr[0];
	for(int i=0;i<size;i++)
	{
		if(min<arr[i])
		min=arr[i];
		if(max>arr[i])
		max=arr[i];
	}
	cout<<"\nThe minimum value in the array is: "<<min<<endl;
	cout<<"The maximum value in the array is: "<<max<<endl;
}
int main()
{
	int size;
	cout<<"\nEnter the number of elements you want to insert in the array: ";
	cin>>size;
	int *arr= new int(size);
	Input(arr,size);
	MinMax(arr,size);
	delete [] arr;

 return 0;
}
