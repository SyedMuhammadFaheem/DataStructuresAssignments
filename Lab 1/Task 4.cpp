#include <bits/stdc++.h>
using namespace std;
int Factors(int num)
{
	static int fact,i=1,sum=0;
	if(num==-1)
	{
	 i=1;sum=0;
	 return 0;
	}
	int n=0;
		if(num%i==0)
		{
			fact=i;
			sum+=fact;
			i++;
			return fact;
			
		}
		i++;
	if(i>num)
	return sum;	
	return 0;

}
int main()
{
	int num,i,var;
	cout<<"\t\tEnd the programme by pressing -1\n\n";
	while(1)
	{
		cout<<"Enter the number: ";
		cin>>num;
		if(num==-1)
		break;
		cout<<"\nThe factors of "<<num<<" are: "<<endl<<endl;
		i=1;
		while(i<=num)
		{
			var=Factors(num);
			if(var>0)
			cout<<var<<" ";
			i++;
		}
		cout<<"\n\nThe sum of all the factors is: "<<Factors(num)<<endl<<endl;
		Factors(-1);
	}
	cout<<"\n\nProgramme Ended!"<<endl;
 return 0;
}
