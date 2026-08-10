#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
    string name;
    string address;
public:
    Person(string n= "",string addr= "")
        : name(n), address(addr)
    {}
    void getdata()
    {
        cout<<"Enter Name: ";
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
    }
    void showdata()
    {
        cout<<"Name: " <<name<<endl;
        cout<<"Address: "<<address<<endl;
    }
};
class Qualification
{
private:
    string qualification;
public:
    Qualification(string q= "")
        : qualification(q)
     {}   
    void getdata()
    {
        cout<<"Enter Qualification: ";
        getline(cin, qualification);
    }
    void showdata()
    {
        cout<<"Qualification: "<<qualification<<endl;
    }
};
class Employee:public Person, public Qualification
{
private:
    int empID;
public:
    Employee(string n= "",string addr= "",string qual= "",int id=0)
        : Person(n, addr), Qualification(qual), empID(id)
    {}
    void getdata()
    {
        Person::getdata();
        Qualification::getdata();
        cout << "Enter Employee ID : ";
        cin >> empID;
    }
    void showdata()
    {
        cout << "----- Employee Record -----"<<endl;
        Person::showdata();
        Qualification::showdata();
        cout<<"Employee ID: "<<empID<<endl;
    }
};
int main()
{
    Employee e;
    e.getdata();
    cout<<endl;
    e.showdata();
    return 0;
}
