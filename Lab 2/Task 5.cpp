#include <bits/stdc++.h>  // docs faheem
using namespace std;
void CalculateGPA(float **a,int r,int size[],string *names)
{
	float sum=0;
	cout<<"The GPA of the Students are: "<<endl;
	for(int i=0;i<r;i++)
	{
		sum=0;
		for(int j=0;j<size[i];j++)
		{
			sum+=a[i][j];
		}
		cout<<"\n\n";
		cout<<"The GPA of "<<names[i]<<" is: "<<sum/(size[i]*3)<<endl;;
	}
}
int main()
{
	int r,r1;
	cout<<"Enter the number of students you want to make the record of: ";
	cin>>r;
	string* names= new string[r];
	cout<<"\nEnter the number of subjects you want to enter: ";
	cin>>r1;
	string* subjects= new string[r1];
	float** gpa=new float*[r];
	int size[r];
	for(int i=0;i<r;i++)
	{
		cout<<"Enter the number of Subjects for Student "<<i+1<<": ";
		cin>>size[i];
		gpa[i]=new float[size[i]];
	}
	
	cout<<"\n\nEnter the name of the Students: "<<endl;
	for(int i=0;i<r;i++)
	{
		cout<<"Student "<<i+1<<": ";
		fflush(stdin);
		getline(cin,names[i]);
	}

	cout<<"\n\nEnter the name of the Subjects: "<<endl;
	for(int i=0;i<r1;i++)
	{
		cout<<"Subject "<<i+1<<": ";
		fflush(stdin);
		getline(cin,subjects[i]);
	}
	
	cout<<"\n\nEnter the subject-wise GPA of the Students: "<<endl;
	for(int i=0;i<r;i++)	
	{
		cout<<"Enter the academic record of "<<names[i]<<": "<<endl;
		for(int j=0;j<size[i];j++)
		{
			cout<<subjects[j]<<" GPA: ";
			cin>>gpa[i][j];
		}
		cout<<"\n\n";
	}
	CalculateGPA(gpa,r,size,names);
	


 return 0;
}

