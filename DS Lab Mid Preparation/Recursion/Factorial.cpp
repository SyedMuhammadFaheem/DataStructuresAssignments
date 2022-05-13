#include <iostream> //docs faheem
using namespace std;
int Factorial(int n)
{
    if(n==0 || n==1)
    return 1;
    else
    return n*Factorial(n-1);
}
int main()
{
    int num;
    cout<<"Enter the number you want to take the factorial of: ";
    cin>>num;
    cout<<"The Factorial of the number "<<num<<" is: "<<Factorial(num)<<endl;


   
   return 0;
}