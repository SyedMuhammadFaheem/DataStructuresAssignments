#include <bits/stdc++.h>
using namespace std;
int Invert(int array[],int n)
{
    int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(array[i]>array[j])
			{
			    count++;
			}
		}
	}
	return count;
    
}
int main() {
	// use standard input and output (no file i/o required)
	// TODO: Your solution here
	int size;
	cin>>size;
	int array[size];
	for(int i=0;i<size;i++)
	{
	    cin>>array[i];
	}
	cout<<Invert(array,size);
	return 0; // always return 0 from here
}
int isSorted;
    for(int i=1;i<n;i++)
    {
        if(array[i-1]<array[i])
        {
            isSorted=0;
        }
        else
        {
            isSorted=1;
        }
    }
    if(isSorted==1)
    return true;
    else
    false;



bool checkSort(int array[],int n)
{
    int isSorted;
    for(int i=0;i<n;i++)
    {
        isSorted=1;
        
        for(int j=0;j<(n-i)-1;j++)
        {
            if(array[j]>array[j+1])
                isSorted=0;
        }
        
        if(isSorted==1)
        return true;
        else false;
    }
}
int main() {
	int n;
	cin>>n;
	int *arr=new int[n];
	int inv=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			inv++;
		}
	}
	cout<<inv<<endl;
	delete [] arr; 
}
