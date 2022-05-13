#include <bits/stdc++.h>  // docs faheem
using namespace std;
void Pattern(int array[],int rows)
{
	int arr[rows],max=array[0],min=9999,temp1=-1,temp2=-1,j=0;
	while(j<rows)
	{
		for(int i=0;i<rows;i++)
		{
			if(array[i]==-1)
			continue;
			if(max<array[i])
			{
			    max=array[i];
			    temp1=i;
			}
			if(min>array[i])
			{
				min=array[i];
				temp2=i;
			}
		}
		arr[j]=max;
		j++;
		arr[j]=min;
		j++;
		array[temp1]=-1;
		array[temp2]=-1;
		max=array[0];
		min=9999;
	}
	cout<<"The elements of the array in the specified order are: ";
	for(int i=0;i<rows;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int rows;
	cout<<"Enter the nuumber of rows you want to enter: ";
	cin>>rows;
	int* array=new int[rows];
	cout<<"Populate the Linear array in a sorted manner: "<<endl;
	for(int i=0;i<rows;i++)
	{
		cout<<"Element "<<i<<": ";
		cin>>array[i];
	}
	Pattern(array,rows);


 return 0;
}

