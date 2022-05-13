#include <iostream> //docs faheem
using namespace std;
struct Date{
    int date,month,year;
}D[5];
void SelectionSort(struct Date* d)
{
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(d[i].year>d[j].year)
            {
                d[i].year=d[i].year+d[j].year;
                d[j].year=d[i].year-d[j].year;
                d[i].year=d[i].year-d[j].year;
            }
        }
    }
}
void Input(struct Date* d)
{
    cout<<"Enter the day, month and year orderwise: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter the date: ";
        cin>>d[i].date>>d[i].month>>d[i].year;
    }

}
void Display(struct Date* d)
{
    cout<<"The dates after sorting by year are: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<d[i].date<<" "<<d[i].date<<" "<<d[i].date<<endl;
    }
}
int main()
{
    Input(D);
    SelectionSort(D);
    Display(D);
   return 0;
}