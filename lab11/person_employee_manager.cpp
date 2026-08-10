#include<iostream>
#include<string>
using namespace std;
class person
{
	protected:
		string name;
		string address;
	public:
		person(string n, string addr)
		   : name(n), address(addr)
		   {}
		void showperson()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"address: "<<address<<endl;
		}
};
class Employee : public person
{
	protected:
		int empID;
	public:
		Employee(string n, string addr, int id)
		   :person(n,addr), empID(id)
		   {}
		void showEmployee()
		{
			showperson();
			cout<<"Employee ID: "<<empID<<endl;
		}
};
class Manager:public Employee
{
private:
    string qualification;
public:
    Manager(string n,string addr,int id,string qual)
        : Employee(n,addr,id),qualification(qual)
          {}
    void showManager()
    {
        showEmployee();
        cout<<"Qualification: "<<qualification<<endl;
    }
};
int main()
{
    Manager mgr("Sara Ahmed","Lahore",1042,"MBA");
    cout<<"===== Manager Profile ====="<<endl;
    mgr.showManager();
    cout<<endl;
    Manager mgr2("Usman Ali","Karachi",2075,"PhD Computer Science");
    cout<<"===== Manager Profile ====="<<endl;
    mgr2.showManager();
    return 0;
}
