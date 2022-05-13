#include <bits/stdc++.h>  // docs faheem
using namespace std;
class Student
{
        string name;
        int rollno;
        string program;
        string phone;
        string address;
    
    public:
    	Student()
		{
		}
        void Input()
        {
            cout<<"Enter the Name of the Student: ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Enter the Roll Number: ";
            cin>>rollno;
            cout<<"Enter the Degree Programme: ";
            fflush(stdin);
            getline(cin,program);
            cout<<"Enter Phone Number: ";
            fflush(stdin);
            getline(cin,phone);
            cout<<"Enter Home Address: ";
            fflush(stdin);
            getline(cin,address);
        }
        
        string getName()
        {
            return name;
        }
        
        void Display()
        {
            cout<<"Student Name: "<<name<<endl;
			cout<<"Phone Number: "<<phone<<endl;
			cout<<"Roll Number: "<<rollno<<endl;
			cout<<"Degree Programme: "<<program<<endl;
			cout<<"Home Adress: "<<address<<endl;
        }
};
void Sort(Student *obj)
{
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			if(obj[i].getName()<obj[j].getName())
			{
				Student temp;
				temp=obj[i];
				obj[i]=obj[j];
				obj[j]=temp;
			}
			
		}
	}
}
int main()
{
	Student *S = new Student[5];
	for(int i=0;i<5;i++)
	{
		S[i].Input();
	}
	cout<<"Displaying Details before sorting: "<<endl;
	for(int i=0;i<5;i++)
	{
		S[i].Display();
	}
	Sort(S);
	cout<<"Displaying Details after sorting: "<<endl;
	for(int i=0;i<5;i++)
	{
		S[i].Display();
	}

 return 0;
}

