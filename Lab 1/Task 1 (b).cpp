#include <bits/stdc++.h>
using namespace std;
int main(int argc,char **argv)
{
	argc=0;
	cout<<"The argument count is: "<<argc<<endl;
	for(int i=0;*argv[i]!='\0';i++)
	{
		cout<<argv[i];
		i++;
	}
 return 0;
}
