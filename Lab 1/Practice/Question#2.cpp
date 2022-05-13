#include <bits/stdc++.h>  // docs faheem
using namespace std;
class Employee
{
	string name
	int age; 
	float salary; 
	float experience;
	float workinghours;
	
	public: 
		Employee()
	    {		
		}
		void Input()
		{
			cout<<"Enter the name of the Employee: ";
			fflush(stdin);
			getline(cin,name);
			cout<<"Enter the age of the Employee: "; 
			cin>>age;
			cout<<"Enter the experience of the Employee: "; 
			cin>>experience;
			cout<<"Enter the Working hours of the Employee: "; 
			cin>>workinghours;
			
		}
		void CalculateSalary()
	    {
			if(age>50 && experience>10 && workinghours>240)
	  		salary=workinghours*500;
	  		
			else if((age<=50 && age>40) && (experience<=10 && experience>6) && (workinghours>200 && workinghours<=240)) 
			salary=workinghours*425;
			
			else if((age<=40 && age>30) && (experience<=6 && experience>3) && (workinghours>160 && workinghours<=200)) 
			salary=workinghours*375;
			
			else if( (age <= 30 && age>22) && (experience <=3 && experience> 1) && (workinghours >120 && workinghours<=160))
			salary=workinghours*300;
			
			else
			cout<<"Invalid Parameters Given!"<<endl;
			
	}
	void Display()
	{
		cout<<"Name of the Employee: "<<name<<endl;
		cout<<"Age of the Employee: "<<age<<endl;
		cout<<"Working Experience of the Employee: "<<experience<<endl;
		cout<<"Working hours of the Employee: "<<workinghours<<endl;
		cout<<"Employee Salary: "<<salary<<endl;
	}
int main()
{
	int num;
	cout<<"Enter the number of employees you want to enter: ";
	cin>>num;
	Employee *E= new Employee[num];
	
	for(int i=0;i<num;i++)
	{
		E[i].Input();
	}
	
	for(int i=0;i<num;i++)
	{
		E[i].Display();
	}

 return 0;
}

