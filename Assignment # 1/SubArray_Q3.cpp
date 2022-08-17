#include <iostream> //docs faheem
using namespace std;
int main()
{
//     14 -12 -23 67 12 -97 45 -10 90 -6
    int n;
    cin>>n;
	int* arr=new int[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	int m=-999;
	for(int i=0;i<n;i++)
	{
	    if(m<arr[i])
	    m=arr[i];
	}
	int k=n,sum=0,max=-999,i=0,j,size,*temp,check=1;
	temp=new int[size];
	while(i<k)
	{
	    sum=0;
	    j=i;
	    while(j<k)
	    {
	        sum+=arr[j];
	        j++;
	    }
	    if(max<sum)
	    {
	        max=sum;
	        check=1;
	    }
	    else
	    {
	        check=0;
	    }
	    if(check==1)
	    {
	        j=i;    
	        delete [] temp;
	        int l=0;
	        size=(k-i);
	        temp=new int[size];
    	    while(j<k)
    	    {
    	     	 temp[l]=arr[j];
        	     l++;
        	     j++;
    	    }
	    }
	    
	    if(arr[k-1]!=m)
	    k--;
	    i++;
	}
	for(i=0;i<size;i++)
	{
	    cout<<temp[i]<<" ";
	}
	cout<<endl<<max<<endl;


   
   return 0;
}
