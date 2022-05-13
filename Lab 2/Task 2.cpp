#include <bits/stdc++.h>		//docs faheem
using namespace std;
void AscendingOrder(int array[])
{
	int min=99999, max=0;
	for(int i=0;i<10;i++)
	{
		if(min>array[i])
		min=array[i];
		if(max<array[i])
		max=array[i];
	}
	cout<<"Ascending Order: "
	cout<<min<<" ";
	min++;
	while(min<=max)
	{
		for(int j=0;j<10;j++)
		{
			if(min==array[j])
			cout<<min<<" ";
		}
		min++;
	}
	
}
void DescendingOrder(int array[])
{
	int max=0;
	for(int i=0;i<10;i++)
	{
		if(max<array[i])
		max=array[i];
	}
	cout<<"Descending Order: ";
	cout<<max<<" ";
	max--;
	while(max>=0)
	{
		for(int j=0;j<10;j++)
		{
			if(max==array[j])
			cout<<max<<" ";
		}
		max--;
	}
}
int main()
{
	int *array=new int [10];
	cout<<"Enter the elements: "<<endl;
	for(int i=0;i<10;i++)
	{
		cin>>array[i];
	}
	AscendingOrder(array);
	cout<<endl;
	DescendingOrder(array);
	return 0;
}
