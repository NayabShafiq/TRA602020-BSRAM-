#include<iostream>
using namespace std;
int main()
{
	float arr[10]={10.1,20.2,30.3,40.4,50.5,60.6,70.7,80.8,90.9,100.10};
	float *ptr;
	ptr=arr;
	cout<<"All elemets of the floating array  : "<<endl;
	for(int i=9;i>=0;i--)
	{
		cout<<*(ptr+i)<<endl;
	}
}
