#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cout<<"Enter two integer values : "<<endl;
	cin>>a>>b;
	int *ptrA;
	ptrA=&a;
	int *ptrB;
	ptrB=&b;
	cout<<"The value of integer a : "<<*ptrA<<endl;
	cout<<"The value integer b : "<<*ptrB<<endl;
}
