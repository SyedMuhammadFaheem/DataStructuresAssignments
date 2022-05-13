#include <iostream>
#include <string>
using namespace std;
int main()
{
    int row,col,count=0,ZeroCount=0;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>col;
    int** array=new int*[row];
    for(int i=0;i<row;i++)      //dynamically allocating a 2D array
    {
        array[i]=new int[col];
    }
    cout<<"Populate the 2D Array: "<<endl;
    for(int i=0;i<row;i++)          //Inputting the elements
    {
        for(int j=0;j<col;j++)
        {
            cout<<"Element "<<i<<" "<<j<<": ";
            cin>>array[i][j];
        }
    }  
    bool var=true;
    int i;
    for(i=0.;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(array[i][j]==1 && i==j)
            {
                count++;
            }
            else if(array[i][j]==0)
            {
                ZeroCount++;
            }
            else
            	continue;
            
        }

        if(count>1 || ZeroCount>row-1)
        {
            cout<<"The Matrix entered is not an Identity Matrix!"<<endl;
            break;
        }
        count=0;
        ZeroCount=0;
    } 
	if(count==0 && ZeroCount==0) 
    cout<<"The Matrix entered is an Identity Matrix!"<<endl;
    return 0;
}
