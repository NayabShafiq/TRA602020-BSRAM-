#include<iostream>
using namespace std;
struct Data
{
	char name[20];
	char color[20];
};
struct Car
{
	int model;
	int topSpeed;
	int gears;
	Data d;
};
int main()
{
	Car c;
	cout<<"Enter car name: ";
	cin>>c.d.name;
	cout<<"Enter car color: ";
	cin>>c.d.color;
	cout<<"Enter car model: ";
	cin>>c.model;
	cout<<"Enter top speed: ";
	cin>>c.topSpeed;
	cout<<"Enter Number of gears: ";
	cin>>c.gears;
	if(c.topSpeed > 200 && c.gears > 4)
	{
		cout<<"\n\t====Car Details====";
		cout<<"\nName: "<<c.d.name;
		cout<<"\nColor: "<<c.d.color;
		cout<<"\nModel: "<<c.model;
		cout<<"\nTop Speed: "<<c.topSpeed;
		cout<<"\nNo of Gears: "<<c.gears;
	}
	else
	{
		cout<<"\nCar is not suitable for the race.";
	}
}
