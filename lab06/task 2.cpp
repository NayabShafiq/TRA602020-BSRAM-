#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	int Roll_No; 
	string Name;
	char Section; 
	float CGPA;
};
int main()
{
	student s[2];
	ofstream fout("student.txt");
	for(int i=0;i<2;i++)
	{
		cout<<i+1<<"-Student "<<"roll no: ";
	    cin>>s[i].Roll_No;
	    cout<<"Student name: ";
	    cin.ignore();
	    getline(cin,s[i].Name);
	    cout<<"Section: ";
	    cin>>s[i].Section;
	    cout<<"CGPA: ";
	    cin>>s[i].CGPA;
	    cout<<endl;
	    fout<<i+1<<"-Student record:\n\n";
	    fout<<"Student name: "<<s[i].Name<<endl;
	    fout<<"Roll No: "<<s[i].Roll_No<<endl;
	    fout<<"Section: "<<s[i].Section<<endl;
	    fout<<"CGPA: "<<s[i].CGPA<<endl;
	    fout<<endl;
	}
	fout.close();
	ofstream app("student.txt", ios::app);
	app<<"\n\t===2 students===";
	app.close();
	
	ifstream fin("student.txt");
	string line;
	cout<<"\t===Student recordes===\n";
	while(getline(fin,line))
	{
		cout<<line<<endl;
	}
	fin.close();
}
