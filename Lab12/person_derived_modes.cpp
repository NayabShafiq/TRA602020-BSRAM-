#include<iostream>
#include<string>
using namespace std;
class Person
{
	private:
		string name;
		int age;
	public:
		Person(string n,int a) : name(n),age(a) {}
		void setName(string n)
		{
			name = n;
		}
		void setAge(int a)
		{
			age = a;
		}
		string getName()
		{
			return name;
		}
		int getAge()
		{
			return age;
		}
		void showPerson()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
		}
};
class Student : public Person
{
	private:
		int rollNumber;
	public:
		Student(string n, int a, int r)
		: Person(n, a), rollNumber(r) {}
		void showStudent()
		{
			showPerson();
			cout<<"Roll Number: "<<rollNumber<<endl;
		}
}; 
class Employee : protected Person
{
	private:
		int empID;
	public:
		Employee(string n, int a, int e)
		: Person(n, a), empID(e) {}
		void showEmployee()
		{
			showPerson();
			cout<<"Employee ID: "<<empID<<endl;
		}
}; 
class Teacher : private Person
{
	private:
		string subject;
	public:
		Teacher(string n, int a, string s)
		: Person(n, a), subject(s) {}
		void showTeacher()
		{
			showPerson();
			cout<<"Subject: "<<subject<<endl;
		}
}; 
int main()
{
	Student stu("Nayab Shafiq", 19, 002);
	Employee emp("Jiya Khan", 20, 2088);
	Teacher tchr("Dr.Zunaira", 25, "Biology");
	cout<<"---- Student ----"<<endl;
	stu.showStudent();
	cout<<"Direct Call ok: "<<stu.getName()<<endl;
	cout<<endl;
	cout<<"---- Employee ----"<<endl;
	emp.showEmployee();
	cout<<"---- Teacher ----"<<endl;
	tchr.showTeacher();
}
