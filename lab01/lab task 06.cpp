#include<iostream>
using namespace std;
int main()
{
	char str[100];
	cout<<"Enter a string : "<<endl;
	cin.getline(str,100);
	char *ptr;
	ptr=str;
	int length=0;
	while(*ptr!='\0')
	{
		length++;
		ptr++;
	}
	cout<<"The length of the string : "<<length;
}
