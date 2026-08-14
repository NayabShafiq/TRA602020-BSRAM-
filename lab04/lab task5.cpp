#include<iostream>
using namespace std;
struct student
{
	string name;
	int rollNo;
	float marks[3];
	float gpa;
};
void CalculateGPA(student &s)
{
	float sum=0;
	for(int i=0 ; i<3 ; i++)
	{
		sum = sum+s.marks[i];
	}
	float avg = sum/3;
	s.gpa=(avg/100)*4;
}
void displaystudent(student s)
{
	cout<<"Student details:"<<endl;
	cout<<"Name: "<<s.name<<endl;
	cout<<"Roll No: "<<s.rollNo<<endl;
	cout<<"Marks: ";
	for(int i=0 ; i<3 ; i++)
	{
		cout<<s.marks[i]<<" ";
	}
	cout<<"\nGPA: "<<s.gpa<<"/4.0"<<endl;
}
int main()
{
	student s[2];
	for(int i=0 ; i<2 ; i++)
	{
	cout<<"Enter name:";
	cin>>s[i].name;
	cout<<"Enter Roll No:";
	cin>>s[i].rollNo;
	cout<<"Enter marks for 3 Subjects:";
	for(int j=0 ; j<3 ; j++)
	{
		cin>>s[i].marks[j];
	}
	CalculateGPA(s[i]);
    }
    for(int i=0 ; i<3 ; i++)
    {
    	displaystudent(s[i]);
	}
	return 0;
}
