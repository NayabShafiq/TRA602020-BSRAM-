#include<iostream>
using namespace std;
struct Result
{
	int marks;
	char grade;
};
struct Record
{
	int rollNo;
	Result res;
};
int main()
{
	Record R;
	cout<<"Enter Roll No: ";
	cin>>R.rollNo;
	cout<<"Enter Marks: ";
	cin>>R.res.marks;
	cout<<"Enter Grade: ";
	cin>>R.res.grade;
	cout<<"\n\tRecord Details";
	cout<<"\nRoll No: "<<R.rollNo;
	cout<<"\nMarks: "<<R.res.marks;
	cout<<"\nGrades: "<<R.res.grade;
}
