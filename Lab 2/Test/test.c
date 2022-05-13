#include<iostream>
using namespace std;

int main()
{
	int n,m;
	bool** arr= new int*[5];
	for(int i=0;i<5;i++)
	{
		arr[i]= new int[5];
	}
	arr[0][0]=arr[0][2]=arr[1][1]=arr[1][3]=arr[2][0]=arr[2][2]=arr[2][3]=arr[2][4]=arr[3][1]=arr[3][2]=arr[3][3]=arr[4][2]=arr[4][4]= false;
	arr[0][1]=arr[0][3]=arr[0][4]=arr[1][0]=arr[1][2]=arr[1][4]=arr[2][1]=arr[3][0]=arr[3][4]=arr[4][0]=arr[4][1]=arr[4][3]=true;
	
	for(int i=0; i<5;i++){
		for(int j=0;j<5;j++){
			if(arr[i][j]==true){
				cout<<"* ";
			}else{
				cout<<"  ";
			}if(j==4){
				cout<<endl;
			}
		}
	}
	cout<<endl<<"Enter two numbers: ";
	cin>>n>>m;
	if(arr[n][m]==true){
		cout<<"common friend of "<<n<<" and "<<m;
	}else{
		cout<<"no common friend of "<<n<<" and "<<m;
	}
}
