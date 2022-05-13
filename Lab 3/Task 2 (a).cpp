#include <bits/stdc++.h>  // docs faheem
using namespace std;
int i=1;
void Sequence2(int num,int n);
void Sequence(int num,int n)
{
	if(i==num)
	return;
	else
	{
		Sequence2(num,n);
	}
}
void Sequence2(int num,int n)
{
	cout<<n<<" ";
	i++;
	return Sequence(num,n+i);
}
int main()
{
	int num,n=1;
	cout<<"Enter the size of the sequence: ";
	cin>>num;
	Sequence(num,n);


 return 0;
}

