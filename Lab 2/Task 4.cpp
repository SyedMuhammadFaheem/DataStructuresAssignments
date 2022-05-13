#include <bits/stdc++.h>		//docs faheem
using namespace std;
void DisplayPattern(bool **p)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(*(*(p+i)+j)==true)
			{
				cout<<"["<<i<<"]"<<"["<<j<<"]"<<": ";
				cout<<"*   ";
			}
		}
		
		cout<<endl<<endl;
		
	}
}
SearchFriend(bool **p)
{
	int row,col;
	cout<<"\nEnter the two positions to check for a friend: ";
	cin>>row>>col;
	
	if(*(*(p+row)+col)==true)
	cout<<"The given position is the common friend of "<<row<<" and "<<col<<endl;
	else
	cout<<"The given position doesnot have any common friend of "<<row<<" and "<<col<<endl;
}
int main()
{
	bool** array= new bool*[5];
	for(int i=0;i<5;i++)
	{
		array[i]= new bool[5];
	}
	array[0][0]=array[0][2]=array[1][1]=array[1][3]=array[2][0]=array[2][2]=array[2][3]=array[2][4]=array[3][1]=array[3][2]=array[3][3]=array[4][2]=array[4][4]= false;
	array[0][1]=array[0][3]=array[0][4]=array[1][0]=array[1][2]=array[1][4]=array[2][1]=array[3][0]=array[3][4]=array[4][0]=array[4][1]=array[4][3]=true;
	
	DisplayPattern(array);
	SearchFriend(array);
	
	
	return 0;
}
