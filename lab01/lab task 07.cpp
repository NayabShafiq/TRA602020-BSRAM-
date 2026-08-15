#include<iostream>
using namespace std;
int main()
{
	int arr[8];
	int *ptr;
	ptr=arr;
	cout<<"Enter 8 integer elements : "<<endl;
	for(int i=0;i<8;i++)
	{
		cin>>*(arr+i);
	}
	for(int i=0;i<8;i++)
	{
		if(arr[i]>*ptr)
		{
			*ptr=arr[i];
		}
	}
	cout<<"The max value of the integral data set : "<<endl;
	cout<<*ptr;
}
