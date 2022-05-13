#include <iostream>
using namespace std;
int EvenSequence(int n,int x)
{
	static int sum=0;
	if(x==n )
	{
		if(x%2==0)
		sum+=x;
		return sum;
	}
	else
	{
		if(x%2==0)
		{
			sum+=x;
			return EvenSequence(n,x+1);
		}
		else
		return EvenSequence(n,x+1);
	}
}
int main()
{
	int n,x=1;
	cin>>n;
	cout<<EvenSequence(n,x)<<endl;
	
	return 0;
}
