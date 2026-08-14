#include<iostream>
using namespace std;
struct Account
{
	string accountNumber; 
	string holderName;
	double balance;
};
Account creatAccount()
{
	Account a;
	cout<<"\t===Creat New Account===\n";
	cout<<"Enter account number: ";
	cin>>a.accountNumber;
	cout<<"Enter holder name: ";
	cin.ignore();
	getline(cin , a.holderName);
	cout<<"Enter balance: ";
	cin>>a.balance;
   	return a;
}
void deposit(Account &a , double amount)
{
	a.balance += amount;
	cout<<"\t===Deposit respite===\n";
	cout <<"Account: "<<a.accountNumber<<endl;
	cout<<"Holder: "<<a.holderName<<endl;
	cout<<"Deposited: Rs. "<<amount<<endl;
	cout<<"Balance: Rs."<<a.balance<<endl;
}
bool withdraw(Account &a , double amount)
{
	if(amount <= a.balance)
	{
		a.balance -= amount;
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	Account acc = creatAccount();
	deposit(acc,5000);
	if(withdraw(acc,2000))
	{
		cout<<"\n\tWithdrawal Successful!\n"<<endl;
		cout<<"\nBalance after withdrawal: Rs. "<<acc.balance<<endl;
	}
	if(!withdraw(acc,10000))
	{
		cout<<"\nInsufficient funds!\n"<<endl;
		cout<<"Required: Rs.10000 and  Available: Rs."<<acc.balance<<endl;
	}
	cout<<"\nFinal balance: Rs."<<acc.balance<<endl;
	return 0;
}
