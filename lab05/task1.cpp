#include<iostream>
using namespace std;
struct book
{
	int id;
	float price;
	int pages;
};
void input(book*b,int n);
void output(book*b,int n);
void mostCostly(book*b,int n);
int main()
{
	book b[2];
	int choice;
	cout<<"enter 2 books record 1st time:"<<endl;
	input(b,2);
	cout<<"\t\n--enter choice--(1 or 2):\n";
	cin>>choice;
	if(choice==1)
	{
		mostCostly(b,2);
	}
	else if(choice==2)
	{
		cout<<"\nenter books record 2nd time:"<<endl;
		input(b,2);
		cout<<"second time data is:"<<endl;
		output(b,2);
	}
}
void input(book*b,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nENTER BOOK"<<i+1<<endl;
		cout<<"ID:";
		cin>>b[i].id;
		cout<<"Enter price: ";
		cin>>b[i].price;
		cout<<"Enter book pages: ";
		cin>>b[i].pages;
	}
}
 void output(book*b,int n)
 {
 	for(int i=0;i<n;i++)
 	{
 		cout<<"\nENTER BOOK"<<i+1<<endl;
 		cout<<"ID: "<<b[i].id<<endl;
 		cout<<"Price: "<<b[i].price<<endl;
 		cout<<"Pages: "<<b[i].pages<<endl;
	 }
 }
 void mostCostly(book*b,int n)
 {
 	int max=0;
 	for(int i=1;i<n;i++)
 	{
 		if(b[i].price>b[max].price)
 		{
 			max=i;
		}
    }
        cout<<"\t\n===Most Costly Book Details===\n";
        cout<<"ID: "<<b[max].id<<endl;
 		cout<<"Price: "<<b[max].price<<endl;
 		cout<<"Pages: "<<b[max].pages<<endl;
 }
 
