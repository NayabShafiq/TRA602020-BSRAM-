#include<iostream>
using namespace std;
struct Patient
{
	int id;
	char name[20];
	float temp;
	int severity;
};
int input(Patient p[] , int n)
{
 for(int i=0;i<n;i++)
 {
	cout<<"\nPatient-"<<i+1<<endl;
	cout<<"ID: ";
	cin>>p[i].id;
	cout<<"Name: ";
	cin>>p[i].name;
	cout<<"Temp: ";
	cin>>p[i].temp;
	cout<<"Severity: ";
	cin>>p[i].severity;
 }
 return 0;
}
Patient*mostCritical(Patient p[] ,int n)
{
	int max=p[0].severity;
	Patient*ptr=&p[0];
	for(int i=1;i<n;i++)
	{
		if(p[i].severity>max)
		{
			max=p[i].severity;
			ptr=&p[i];
		}
	}
	return ptr;
}
int display(Patient*p)
{
	cout<<"ID: "<<p->id<<endl;
	cout<<"Name: "<<p->name<<endl;
	cout<<"Temp: "<<p->temp<<endl;
	cout<<"Severity: "<<p->severity<<endl;
	return 0;
}
int update(Patient p[] ,int n)
{
	int id;
	cout<<"\nEnter ID to update: ";
	cin>>id;
	for(int i=0;i<n;i++)
	{
		if(p[i].id==id)
		{
			cout<<"New Temp: ";
			cin>>p[i].temp;
			cout<<"New Severity: ";
			cin>>p[i].severity;
			cout<<"Update\n";
			return 0;
		}
	}
	cout<<"Patient not found.\n";
	return 0;
}
int main()
{
	int n;
	cout<<"Enter number of Patients: ";
	cin>>n;
	Patient p[50];
	input(p,n);
	cout<<"\nMost Critical Patient:\n";
	Patient*c=mostCritical(p,n);
	display(c);
	update(p,n);
	cout<<"\nAfter Update Most Critical:\n";
	c=mostCritical(p,n);
	display(c);
	return 0;
}
