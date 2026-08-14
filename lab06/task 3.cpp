#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
struct Account
{
	string Name;
	int Account_Number;
	float *deposits;
	float Current_Balance;
};
int main()
{
	Account a[5];
	ofstream fout("details.txt");
	cin.ignore();
	for(int i=0;i<5;i++)
	{
		cout<<"\nAccount Holder "<<i+1<<endl;
		cin.ignore(1000,'\n');
		cout<<"Name: ";
		getline(cin,a[i].Name);
		cout<<"Account Number: ";
		cin>>a[i].Account_Number;
		a[i].deposits=new float[30];
		cout<<"Enter 30-days deposits:\n";
		for(int j=0;j<30;j++)
		{
			cout<<"Day "<<j+1<<": ";
			cin>>a[i].deposits[j];
		}
		cout<<"Current Balance: ";
		cin>>a[i].Current_Balance;
		cin.ignore();
		fout<<"Account Holder "<<i+1<<endl;
		fout<<"Name: "<<a[i].Name<<endl;
		fout<<"Account Number: "<<a[i].Account_Number<<endl;
		fout<<"30-day Deposits: ";
		for(int j=0;j<30;j++)
		{
			fout<<a[i].deposits[j]<<" ";
		}
		fout<<endl;
		fout<<"Current Balance: "<<a[i].Current_Balance<<endl;
	}
	fout.close();
	ifstream fin("details.txt");
	cout<<"\n===Account with Balance 50000===\n\n";
	string temp, name;
	int accNo;
	float balance;
	for(int i=0;i<5;i++)
	{
		getline(fin,temp);
		getline(fin,temp);
		name=temp.substr(6);
		getline(fin,temp);
		accNo=atoi(temp.substr(16).c_str());
		getline(fin,temp);
		getline(fin,temp);
		balance=atof(temp.substr(17).c_str());
		getline(fin,temp);
		if(balance>50000)
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Account Number: "<<accNo<<endl;
			cout<<"Current Balance: "<<balance<<endl;
			cout<<endl;
		}
	}
	fin.close();
	for(int i=0;i<5;i++)
	{
		delete[] a[i].deposits;
	}
}
