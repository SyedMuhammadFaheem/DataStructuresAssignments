#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//Test Cases
// A P + L E
// P E A R S
// + A N + O
// L G Y Y T
// E E L T T
// 3
// A P P L E
// M A N G O
// P E A R S



// 5 5
// F I V E T
// X A C P P
// P U S * S
// P U * H P
// L I + H T
// 4
// F I V E
// C P P
// P U S H
// L I G H T
int main() {
	int row,col;
	cin>>row>>col;
	char** arr=new char*[row];
	for(int i=0;i<row;i++)
	{
	    arr[i]=new char[col];
	}
	for(int i=0;i<row;i++)
	{
	    for(int j=0;j<col;j++)
	    {
	        cin>>arr[i][j];
	    }
	}


	int n;
	cin>>n;
	string* str=new string[n];
	for(int i=0;i<n;i++)
	{
	    cin>>str[i];
	}
	
	string temp;
	int r,c,check=0;
	char direction,start,end;

	for(int i=0;i<n;i++)
	{
		temp=str[i];
		end=temp.size()-1;
		int flag=0;
		for(int k=0;k<row;k++)
		{
			r=k;
			direction='R';
			int tindex=0;
			for(int j=0;j<col;j++)
			{
				if(tindex==end+1)
				flag=1;
				if(temp[tindex]==' ')
				{
					tindex++;
					j--;
					continue;
				}
				if(arr[k][j]=='+')
				{
					if(j==0)
					c=j;
					tindex++;
					continue;
				}
				if(arr[k][j]=='*')
				{
					if(j==0 || j==end)
					{
						check=0;
						break;
					}
					else
					{
						j++;
						if(arr[k][j]=='+')
						{
							check=0;
							break;
						}

						while(arr[k][j]!=temp[tindex] && tindex!=end)
						{
							tindex++;
						}
						continue;
					}


				}
				if(arr[k][j]==temp[0] && j<=end)
				c=j;
				if(arr[k][j]==temp[tindex])
				{
					check=1;
				}
				else
				{
					if(tindex>0 && flag==0)
					{
						check=0;
						break;
					}
					else
					continue;
				}
				tindex++;
			}
			if(check==1)
			{
				cout<<r<<" "<<c<<" "<<direction<<endl;
			}
			check=0;
			c=k;
			direction='D';
			tindex=0;
			flag=0;
			for(int j=0;j<row;j++)
			{
				if(tindex==end+1)
				flag=1;
				if(arr[j][k]=='+')
				{
					if(j==0)
					r=j;
					tindex++;
					continue;
				}
				if(arr[j][k]=='*')
				{
					if(j==0 || j==end)
					{
						check=0;
						break;
					}
					else
					{
						j++;
						if(arr[j][k]=='+')
						{
							check=0;
							break;
						}
						while(arr[j][k]!=temp[tindex] && tindex!=end)
						{
							tindex++;
						}
						continue;
					}
				}
				if(arr[j][k]==temp[0] && j<=end)
				r=j;
				if(arr[j][k]==temp[tindex])
				{
					check=1;
				}
				else
				{
					if(tindex>0 && flag==0)
					{
						check=0;
						break;
					}
					else
					continue;
				}
				tindex++;
			}
			if(check==1)
			cout<<r<<" "<<c<<" "<<direction<<endl;
			check=0;
		}
	}

	
	
	return 0; // always return 0 from here
}
