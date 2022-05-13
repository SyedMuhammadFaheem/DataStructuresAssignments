#include <iostream>
using namespace std;
int Invert(int *array,int low,int next,int n)
{
	static int count=n,c=0;
	if(count==0)
	return c;
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
	  		    c++;
			}
			return Invert(array,low,next+1,n);
		}
		else
		{
			count--;
			return Invert(array,low+1,low+2,n);
		}
		
	}
}
int main() {
	// use standard input and output (no file i/o required)
	// TODO: Your solution here
	// cin>>size;
	int array[5];
	for(int i=0;i<5;i++)
	{
	    cin>>array[i];
	}
	cout<<Invert(array,0,1,5)<<endl;
	return 0; // always return 0 from here
}
