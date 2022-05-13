#include<iostream>
using namespace std;

int sorting(int *arr,int i,int j,int size){
	int temp;
	if(i==size){
 	return 0;
	}
	else{
		if(j<size)
		{
			if(arr[i]>arr[j])
			{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			}
			return sorting(arr,i,j+1,size);
			
		}
		else
		return sorting(arr,i+1,i+2,size);
	}	
}

int main(){
	int size,i=0;
	cout<<"Enter size:";
	cin>>size;
	int* arr=new int[size];
	cout<<"Enter array numbers:";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	cout<<"Array elements: ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	sorting(arr,0,1,size);
	cout<<endl;
	cout<<"AFTER SORTING: "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	
}
