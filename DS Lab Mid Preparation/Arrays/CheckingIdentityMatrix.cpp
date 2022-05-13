#include <iostream> //docs faheem
using namespace std;
void Input(int** arr,int size)
{
    cout<<"Enter the values in the 2D Matrix: \n\n";
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<"Element ["<<i<<"]["<<j<<"]: ";
            cin>>arr[i][j];
        }
    }

}
bool CheckingIdentityMatrix(int** arr,int size)
{
    if(size==1)
    return false;
    int OneCount=0,ZeroCount=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(*(*(arr+i)+j)==1 && i==j)
            ++OneCount;
            else if(*(*(arr+i)+j)==0)
            ++ZeroCount;
            else
            return false;
        }
        if(OneCount>1 || ZeroCount>(size-1))
        return false;
        OneCount=0;
        ZeroCount=0;
    }
    if(OneCount==0 && ZeroCount==0)
    return true;
    return false;
} 
int main()
{
    int size;
    cout<<"Enter the size of the matrix: ";
    cin>>size;
    int** arr=new int*[size];
    for(int i=0;i<size;i++)
    {
        arr[i]=new int[size];
    }
    Input(arr,size);
    if(CheckingIdentityMatrix(arr,size))
    cout<<"The Entered Matrix is an Identity Matrix!"<<endl;
    else
    cout<<"The Entered Matrix is not an Identity Matrix!"<<endl;

   
   return 0;
}