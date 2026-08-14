#include<iostream>
using namespace std;
struct Date
{
	int day;
	int month;
	int year;
};
struct PhoneBook
{
	string name;
	string city;
	string phoneNumber;
	Date d;
};
int main()
{
	PhoneBook p;
	cout<<"Enter name: ";
	cin>>p.name;
	cout<<"Enter city: ";
	cin>>p.city;
	cout<<"Enter PhoneNumber: ";
	cin>>p.phoneNumber;
	cout<<"Enter Date (day,month,year): ";
	cin>>p.d.day>>p.d.month>>p.d.year;
	cout<<"\t===Phone Book Details===\n";
	cout<<"Name: "<<p.name<<endl;
	cout<<"City: "<<p.city<<endl;
	cout<<"Phone number: "<<p.phoneNumber<<endl;
	cout<<"Date: "<<p.d.day<<"/"<<p.d.month<<"/"<<p.d.year<<endl;
	return 0;
}

