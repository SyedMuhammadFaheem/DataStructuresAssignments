#include <bits/stdc++.h>  // docs faheem
using namespace std;
int main(int argc,char **argv)
{
	fstream file1;
	file1.open(argv[1],ios::out);
	if(!file1)
	{
		cout<<"Input File doesn't exist!"<<endl;
		exit(0);
	}
	string str;
	cout<<"Enter the text: ";
	fflush(stdin);
	getline(cin,str);
	file1<<str;
	file1.close();
	fstream file2;
	
	
	file1.open(argv[1],ios::in);
	file2.open(argv[2],ios::out);
	if(!file1 || !file2)
	{
		cout<<"Input or Output file doesn't exist!"<<endl;
		exit(0);
	}
	char ch;
	while(file1)
	{
		file1.get(ch);
		file2.put(ch);
	}
	file1.close();
	file2.close();

 return 0;
}

