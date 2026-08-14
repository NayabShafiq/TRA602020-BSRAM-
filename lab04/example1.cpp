#include<iostream>
using namespace std;
struct Address
{
	char HouseNo[50];
	char City[50];
	char PinCode[50];
};
struct Employee
{
	int Id;
	char Name[50];
	int Salary;
	Address Add;
};
int main()
{
	Employee E;
	cout<<"Enter Employee Id: ";
	cin>>E.Id;
	cout<<"Enter Employee Name: ";
	cin>>E.Name;
	cout<<"Employee Slaray: ";
	cin>>E.Salary;
	cout<<"Employee House no: ";
	cin>>E.Add.HouseNo;
	cout<<"Enter City Name: ";
	cin>>E.Add.City;
	cout<<"Enter Pin Code: ";
	cin>>E.Add.PinCode;
	cout<<"\nDetails of Employee:";
	cout<<"\n\tEmployee ID: " <<E.Id<<endl;
	cout<<"\n\tEmployee Name: "<<E.Name<<endl;
	cout<<"\n\tEmployee Salary: "<<E.Salary<<endl;
	cout<<"\n\tEmployee House No: "<<E.Add.HouseNo<<endl;
	cout<<"\n\tEmployee City: "<<E.Add.City<<endl;
	cout<<"\n\tEmployee Pin Code:"<<E.Add.PinCode<<endl;
}
