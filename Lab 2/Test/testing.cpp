#include <iostream>
using namespace std; 

int main() {
	int *p=new int,a=9;
	cout<<&a<<endl;
	cout<<p<<endl;
	p=&a;
	cout<<&a<<endl;
	cout<<p<<endl;
	delete p;
	cout<<"deleted"<<endl;
		cout<<p<<endl;
return 0;
}

