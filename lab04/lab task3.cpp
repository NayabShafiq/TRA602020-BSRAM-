#include<iostream>
using namespace std;
struct complex
{
	int real;
	int imag;
};
  complex addition(complex a , complex b)
{
	complex result;
	result.real = a.real+b.real;
	result.imag = a.imag+b.imag;
	return result;
}
  complex subtraction(complex a , complex b)
{
	complex result;
	result.real = a.real-b.real;
	result.imag = a.imag-b.imag;
	return result;
}
  complex multiplication(complex a , complex b)
{
	complex result;
	result.real = (a.real*b.real)-(a.imag*b.imag);
	result.imag = (a.real*b.real)+(a.imag*b.imag);
	return result;
}
int main()
{
	complex c1,c2,res;
	cout<<"Enter 1st complex num:"<<endl;
	cin>>c1.real>>c1.imag;
	cout<<"Enter 2nd complex num:"<<endl;
	cin>>c2.real>>c2.imag;
	res=addition(c1,c2);
	cout<<"\nAddition: "<<res.real<<"+"<<res.imag<<"i";
	res=subtraction(c1,c2);
	cout<<"\nSubtraction: "<<res.real<<"+"<<res.imag<<"i";
	res=multiplication(c1,c2);
	cout<<"\nMultiplication: "<<res.real<<"+"<<res.imag<<"i";
}
