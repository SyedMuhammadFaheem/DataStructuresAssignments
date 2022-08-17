#include <iostream>
using namespace std;
int main() {
	// use standard input and output (no file i/o required)
	// TODO: Your solution here
	int** arr=new int*[9];
	for(int i=0;i<9;i++)
	{
	    arr[i]=new int[9];
	    if(i<8)
	    {
    	    for(int j=0;j<8;j++)
    	    {
    	        cin>>arr[i][j];
    	    }
	    }
	}
	int sum;
	for(int i=0;i<8;i++)
	{
	    sum=0;
	    int j;
	    for(j=0;j<8;j++)
	    {
	        sum+=arr[i][j];
	        cout<<arr[i][j]<<" ";
	    }
	    arr[i][j]=45-sum;
	    cout<<arr[i][j]<<endl;
	}
	for(int i=0;i<9;i++)
	{
	    sum=0;
	    int j;
	    for(j=0;j<8;j++)
	    {
	        sum+=arr[j][i];
	    }
	    arr[j][i]=45-sum;
	    cout<<arr[j][i]<<" ";
	}
	
	
	return 0; // always return 0 from here
}
