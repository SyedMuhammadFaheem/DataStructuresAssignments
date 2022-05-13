#include <bits/stdc++.h>  // docs faheem
using namespace std;
void Merge(int array[],int low,int mid,int high)
{
	int i=low,k=low,j=mid+1,arr[100];
	while(i<=mid && j<=high)
	{
		if(array[i]<array[j])
		{
			arr[k]=array[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=array[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		arr[k]=array[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		arr[k]=array[j];
		j++;
		k++;
	}
	for(int i=low;i<=high;i++)
	{
		array[i]=arr[i];
	}
}
void MergeSort(int array[],int low,int high)
{
	if(low<high)
	{
		int mid=(high+low)/2;
		MergeSort(array,low,mid);
		MergeSort(array,mid+1,high);
		Merge(array,low,mid,high);
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
	MergeSort(array,0,n-1);
	Display(array,n);


 return 0;
}

