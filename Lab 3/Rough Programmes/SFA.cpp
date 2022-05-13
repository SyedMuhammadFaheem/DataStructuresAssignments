#include <iostream>  // docs faheem

using namespace std;
class A{
	static int x;
	int a;
	public:
		static int fun()
		{
			x++;
			
		}
		int func()
		{
			a++;
			x++;
		}
};
int A::x=0;
int main()
{
	int x=1,count=0;
	while(x++<100)
	{
		count++;
		x*=x;
		if(x<10)continue;
		if(x>50)break;
	}
	cout<<count;
	return 0;
}

