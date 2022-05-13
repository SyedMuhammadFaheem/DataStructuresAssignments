#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num,i=1,sum=0,fact;
	cout<<"\t\tEnd the programme by pressing -1\n";
	while(1)
	{
		cout<<"\n\nEnter the number: ";
		cin>>num;
		if(num==-1)
		break;
		i=1;
		cout<<endl;
		while(i<=num)
		{
			if(num%i==0)
			{
				fact=i;
				cout<<fact<<" ";
				sum+=fact;
			}
			i++;
		}
		cout<<"\n\nThe sum of all the factors of given number "<<num<<" is: "<<sum<<endl;
	}
	cout<<"\n\nProgramme Ended!"<<endl;

 return 0;
}
