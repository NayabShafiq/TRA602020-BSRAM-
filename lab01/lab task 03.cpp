#include<iostream>
using namespace std;
int main()
{
	int arr[5]={10,20,30,40,50};
	int *ptr;
	ptr=arr;
	for(int i=0;i<5;i++)
	{
		cout<<"Value of Array element "<<i<<" : "<<*(ptr+i)<<endl;
		cout<<"The address of array element "<<i<<" : "<<(ptr+i)<<endl;
	}
}
