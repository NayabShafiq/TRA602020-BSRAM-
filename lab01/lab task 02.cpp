#include<iostream>
using namespace std;
int main()
{
	int arr[6]={5,10,15,20,25,30};
	int *ptr;
	ptr=arr;
	cout<<"elements of the array: "<<endl;
	for(int i=0;i<6;i++)
	{
	    cout<<("%d\n",*ptr)<<endl;
        ptr++;
	}
}
