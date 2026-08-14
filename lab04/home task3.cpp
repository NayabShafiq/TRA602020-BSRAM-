#include<iostream>
using namespace std;
struct Instructor
{
	string name;
	string department;
};
struct Course
{
	string code;
	string name;
	int creditHours;
	int maxSeats;
	int enrolledStudents;
	Instructor ins;
};
bool enrolledStudents(Course &c, int studentNo)
{
	if(c.enrolledStudents < c.maxSeats)
	{
		c.enrolledStudents++;
		cout<<"Enrolling student: "<< studentNo <<" in "<<c.name<<"...Success!\n";
		return true;
	}
	else
	{
		cout<<"Enrolling student: "<< studentNo <<" in "<<c.name<<"...Course Full!\n";
		return false;
	}
}
void displayCourse(Course c)
{
	cout<<"\t===Course Details===\n";
	cout<<"Code: "<<c.code<<endl;
	cout<<"Name: "<<c.name<<endl;
	cout<<"Credit Hours: "<<c.creditHours<<endl;
	cout<<"Instructor: "<<c.ins.name<<"("<<c.ins.department<<"Department)\n";
	cout<<"Seats: "<<c.enrolledStudents<<"/"<<c.maxSeats<<"("<<(c.maxSeats - c.enrolledStudents)<<"remaining)\n";
}
int main()
{
	Course c1,c2;
	c1.code = "CS-301";
	c1.name = " OOP ";
	c1.creditHours = 3;
	c1.maxSeats = 2;
	c1.enrolledStudents = 0;
	c1.ins.name = "Miss Eisha Nawaz";
	c1.ins.department = "CS";

	c2.code = "CS-302";
	c2.name = "Python";
	c2.creditHours = 3;
	c2.maxSeats = 30;
	c2.enrolledStudents = 0;
	c2.ins.name = "Mr. Ali Hassan";
	c2.ins.department = "CS";
	
	enrolledStudents(c1,1);
	enrolledStudents(c1,2);
	enrolledStudents(c1,3);
	
	displayCourse(c1);
	displayCourse(c2);
	return 0;
}
