#include <bits/stdc++.h>  // docs faheem
using namespace std;
void Sequence2(int num,int n);
int i=0;
void Sequence(int num,int n)
{
	if(i==num-1)
	return;
	else
		Sequence2(num,n);	
}
void Sequence2(int num,int n)
{
	cout<<n<<" ";
	if(i==0)
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

