#include<iostream>
using namespace std;
struct Author
{
	string name;
	string nationality;
};
struct book
{
	string title;
	string ISBN;
	double price;
	int year;
	Author a;
};
int main()
{
	book b[3];
	for(int i=0 ; i<3 ; i++)
	{
		cout<<"\n---BOOK DETAILS"<<i+1<<"---\n";
		cout<<"Enter Title: ";
		getline(cin,b[i].title);
		cout<<"Enter ISBN: ";
		getline(cin,b[i].ISBN);
		cout<<"Enter price: ";
		cin>>b[i].price;
		cout<<"Enter Publication year: ";
		cin>>b[i].year;
		cin.ignore();
		cout<<"Enter Aurthor name: ";
		getline(cin,b[i].a.name);
		cout<<"Enter Aurthor Nationality: ";
		getline(cin,b[i].a.nationality);
	}
	    cout<<"\n\n---Book Published after 2015---\n";
		for(int i=0 ; i<3 ; i++)
		{
			if(b[i].year > 2015)
			{
				cout<<"\t*Title*"<<b[i].title<<endl;
				cout<<"\t*ISBN*"<<b[i].ISBN<<endl;
				cout<<"\t*Price*"<<b[i].price<<endl;
				cout<<"\t*Year*"<<b[i].year<<endl;
				cout<<"\t*Name*"<<b[i].a.name<<endl;
				cout<<"\t*Nationality*"<<b[i].a.nationality<<endl;
				
			}
		}
	
}
