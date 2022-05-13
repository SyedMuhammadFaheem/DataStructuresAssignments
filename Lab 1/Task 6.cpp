#include <bits/stdc++.h>
using namespace std;
class Animal
{
	string name,colour,breed,family;
	public:
		Animal()
		{
		}
        void Input()
        {
            cout<<"Enter the Name of the Animal: ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Enter the Colour of the Animal: ";
            fflush(stdin);
            getline(cin,colour);
            cout<<"Enter the Breed name of the Animal: ";
            fflush(stdin);
            getline(cin,breed);
            cout<<"Enter the Family of the Animal: ";
            fflush(stdin);
            getline(cin,family);
        }
        string getName()
        {
            return name;
        }
        
        void Display()
        {
            cout<<"Animal Name: "<<name<<endl;
			cout<<"Colour: "<<colour<<endl;
			cout<<"Breed Name: "<<breed<<endl;
			cout<<"Family Name: "<<family<<endl;
			cout<<"\n\n";
        }
	
};
void Sort(Animal *obj)
{
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			if(obj[i].getName()>obj[j].getName())
			{
				Animal temp;
				temp=obj[i];
				obj[i]=obj[j];
				obj[j]=temp;
			}
			
		}
	}
}
int main()
{
	Animal *A = new Animal[5];
	for(int i=0;i<5;i++)
	{
		A[i].Input();
		cout<<"\n\n";
	}
	cout<<"\t\tDisplaying Details before sorting: "<<endl<<endl;
	for(int i=0;i<5;i++)
	{
		A[i].Display();
	}
	Sort(A);
	cout<<"\t\tDisplaying Details after sorting: "<<endl<<endl;
	for(int i=0;i<5;i++)
	{
		A[i].Display();
	}


 return 0;
}
