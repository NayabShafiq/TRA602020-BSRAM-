#include<iostream>
#include<string>
using namespace std;
class RobotUnit
{
	private:
		string robotName;
		int robotID;
		static int objectCount;
	public:
		RobotUnit()
		{
			robotName = "Unknown";
			robotID = 0;
			objectCount++;
			cout<<"Robotunit "<<robotName<<"ID "<<robotID
			    <<"created.count: "<<objectCount<<endl;
		}
	    RobotUnit(string name , int id)
		{
			robotName = name;
			robotID = id;
			objectCount++;
			cout<<"Robotunit "<<robotName<<"ID "<<robotID
			    <<"created.count: "<<objectCount<<endl;
		}
		~RobotUnit()
		{
			objectCount--;
			cout<<"Robotunit "<<robotName
			<<"distroyed.count: "<<objectCount<<endl;
		}
		static int getCount()
		{
			return objectCount;
		}
		void display() const
		{
			cout<<"Robot: "<<robotName<<"ID: "<<robotID<<endl;
		}
};
int RobotUnit::objectCount = 0;
int main()
{
	cout<<"Objects alive: "<<RobotUnit::getCount()<<endl;
	cout<<endl;
	RobotUnit r1("Scout-1",101);
	RobotUnit r2("Carrier-2",102);
	RobotUnit r3;
	cout<<endl;
	cout<<"Objects alive: "<<RobotUnit::getCount()<<endl;
	RobotUnit *r4 = new RobotUnit("Heap-Bot",200);
	cout<<endl;
	cout<<"Objects alive: "<<RobotUnit::getCount()<<endl;
	delete r4;
	cout<<endl;
	cout<<"Objects alive: "<<RobotUnit::getCount()<<endl;
	cout<<"--- Individual Robot Info ---"<<endl;
	cout<<endl;
	r1.display();
	r2.display();
	r3.display();
	cout<<endl;
	cout<<"--- End of main ---"<<endl;
	cout<<endl;
	return 0;
}
