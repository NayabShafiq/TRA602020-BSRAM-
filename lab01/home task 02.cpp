#include <iostream>
using namespace std;
int main()
{
    int L;
    cout<<"Enter length : ";
    cin>>L;
    cin.ignore();
    char str[100];
    cout<<"Enter string : ";
    cin.getline(str,L+1);
    char *p=str;
    while(*p != '\0') p++;
    p--;
    cout<<"Reverse : ";
    for(char *start=str; p>=start; p--)
	{
        cout<<*p;
    }
    cout<<endl;
    return 0;
}
