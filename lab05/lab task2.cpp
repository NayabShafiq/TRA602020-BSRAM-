#include<iostream>
using namespace std;
struct Citizen
{
	int cnicID;
	char name[30];
	char city[20];
	int age;
};
int main()
{
	Citizen c;
	Citizen *ptr;
	ptr=&c;
	cout<<"Enter CNIC ID: ";
	cin>>ptr->cnicID;
	cout<<"Enter Name: ";
	cin>>ptr->name;
	cout<<"Enter City: ";
	cin>>ptr->city;
	cout<<"Enter Age: ";
	cin>>ptr->age;
	int choice;
	cout<<"\nPress 1 to update city of residence, 0 to display record: ";
	cin>>choice;
	if(choice==1)
	{
		cout<<"Enter new city: ";
		cin>>ptr->city;
		cout<<"\n---UPDATE NADRA RECORD---\n";
		cout<<"CNIC ID: "<<ptr->cnicID<<endl;
		cout<<"Enter Name: "<<ptr->name<<endl;
		cout<<"Enter City: "<<ptr->city<<endl;
		cout<<"Enter Age: "<<ptr->age<<endl;
	}
	else
	{
		cout<<"\n---NADRA RECORD---\n";
		cout<<"CNIC ID: "<<ptr->cnicID<<endl;
		cout<<"Enter Name: "<<ptr->name<<endl;
		cout<<"Enter City: "<<ptr->city<<endl;
		cout<<"Enter Age: "<<ptr->age<<endl;
	}
	return 0;
}
