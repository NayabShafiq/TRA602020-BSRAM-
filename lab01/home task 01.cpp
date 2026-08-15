#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cout<<"Enter the values for five integer variables : "<<endl;
	cin>>a>>b>>c>>d>>e;
	int *ptr[5]={&a,&b,&c,&d,&e};
	cout<<"The value of each element: "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<**(ptr+i)<<endl;
	}
	cout<<"The address of each element: "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<(ptr+i)<<endl;
	}
}
