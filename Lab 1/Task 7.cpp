#include <bits/stdc++.h>  // docs faheem
using namespace std;
class Numbers
{
	string RadixType;
	int *value;
	
	public:
		Numbers()
		{
			value= new int;
			*value=0;
			RadixType="None";
		}
		Numbers(int data,string type)
		{
			value= new int;
			*value=data;
			RadixType=type;
		}
		Numbers(const Numbers &obj)
		{
			value=new int;
			*value=*(obj.value);
			this->RadixType=obj.RadixType;
		}
		void Display()
		{
			cout<<"The Value of the number is: "<<*value<<endl;
			cout<<"The Radix Type of the number is: "<<RadixType<<endl;
			cout<<"\n\n";
		}
		~Numbers()
		{
			delete value;
		}
	
};
int main()
{
	Numbers N1(5,"tens");
	cout<<"Details of Object 1: "<<endl<<endl;
	N1.Display();
	Numbers N2(N1);
	cout<<"Details of Object 2: "<<endl<<endl;
	N2.Display();

 return 0;
}

