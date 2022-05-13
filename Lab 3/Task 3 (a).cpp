#include <bits/stdc++.h>  // docs faheem
using namespace std;
void NormalRecursiveSort(int *array,int low,int next,int n)
{
	static int count=n;
	if(count==0)
	return;
	else
	{
		int temp;
		if(next<n)
		{
			if(array[low]>array[next])
			{
	  		    temp=array[low];
	  		    array[low]=array[next];
	  		    array[next]=temp;
			}
			return NormalRecursiveSort(array,low,next+1,n);
		}
		else
		{
			count--;
			return NormalRecursiveSort(array,low+1,low+2,n);
		}
		
	}
}
void Input(int* array,int n)
{
	cout<<"Enter the values: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Element "<<i<<": ";
		cin>>array[i];
	}
}
void Display(int *array,int n)
{
	cout<<"The values of the array are: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
}

int main()
{
	 int n;
	 cout<<"Enter the size of array: ";
	 cin>>n;
	int array[n];
	Input(array,n);
	NormalRecursiveSort(array,0,1,n);
	Display(array,n);


 return 0;
}

