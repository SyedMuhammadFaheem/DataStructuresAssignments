#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,fact=1;
	cout<<"Enter the number: ";
	cin>>n;
	while(n>0)
	{
		fact*=n;
		n--;
	}
	cout<<"The factorial of the number is: "<<fact<<endl;


 return 0;
}
