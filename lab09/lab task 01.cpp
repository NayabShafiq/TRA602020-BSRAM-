#include<iostream>
#include<string>
using namespace std;
class university;
class student
{
	private:
		string name;
		int marks;
		int semester;
	public:
		student(string n, int m, int s)
		: name(n) , marks(m) , semester(s)
		{}
		friend void display(student , university);
};
class university
{
	private:
		string universityName;
		int ranking;
	public:
		university(string u, int r)
		: universityName(u) , ranking(r) 
		{}
		friend void display(student , university);
};
void display(student s , university u)
{
	cout<<"====Student & University Profile===="<<endl;
	cout<<"Student name: "<<s.name<<endl;
	cout<<"Marks: "<<s.marks<<endl;
	cout<<"Semester: "<<s.semester<<endl;
	cout<<endl;
	cout<<"University: "<<u.universityName<<endl;
	cout<<"Ranking: "<<u.ranking<<endl;
	cout<<"====================================="<<endl;
}
int main()
{
	student s1("Nayab Shafiq",87,4);
	university u1("Superior University",12);
	display(s1,u1);
	return 0;
}
