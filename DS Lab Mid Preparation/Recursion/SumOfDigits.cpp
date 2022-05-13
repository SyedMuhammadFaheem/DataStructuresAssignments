#include <iostream> //docs faheem
using namespace std;
int SumOfDigits(int n)
{
    static int sum=0;
    if(!n)
    return sum;
    else
    {
        sum+=n%10;
        return SumOfDigits(n/10);
    }
}
int main()
{
    //This programme won't work for numbers having leading zeros
    int num;
    cout<<"Enter the number you want to take the sum of the digits of: ";
    cin>>num;
    cout<<"The sum of the digits of the entered number is: "<<SumOfDigits(num);


   
   return 0;
}