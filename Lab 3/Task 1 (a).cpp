#include <bits/stdc++.h>  // docs faheem
using namespace std;
void Sequence(int num,int n)
{
	static int i=1;
	if(i==num)
	return ;
	else
	{
		cout<<n<<" ";
		i++;
		return Sequence(num,n+i);
	}
}
int main()
{
	int num,n=1;
	cout<<"Enter the size of the sequence: ";
	cin>>num;
	Sequence(num,n);

 return 0;
}

