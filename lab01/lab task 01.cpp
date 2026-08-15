#include<iostream>
using namespace std;
int main()
{
	int arr[5]={10,20,30,40,50};
	int *ptr;
	ptr=&arr[2];
	cout<<"Value of third element of the array : "<<*ptr<<endl;
	cout<<"Address of third element of the array : "<<ptr<<endl;
}
