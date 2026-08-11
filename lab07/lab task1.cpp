#include<iostream>
#include<string>
using namespace std;
class Robot
{
	public:
	string robotId; 
	string robotype;
	int Battery;
    float speed;
};
int main()
{
	Robot r1,r2,r3;
	r1.robotId="R-001";
	r1.robotype="Picker";
	r1.Battery=50;
	r1.speed=1.5;
	
	r2.robotId="R-002";
	r2.robotype="Scout";
	r2.Battery=60;
	r2.speed=3.6;
	
	r3.robotId="R-003";
	r3.robotype="Carrier";
	r3.Battery=90;
	r3.speed=3.8;
	
	cout<<"---Robot fleet status---"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"ID: "<<r1.robotId<<endl;
		cout<<"Type: "<<r1.robotype<<endl;
		cout<<"Battery: "<<r1.Battery<<endl;
		cout<<"Speed: "<<r1.speed<<endl;
		cout<<endl;
		cout<<"ID: "<<r2.robotId<<endl;
		cout<<"Type: "<<r2.robotype<<endl;
		cout<<"Battery: "<<r2.Battery<<endl;
		cout<<"Speed: "<<r2.speed<<endl;
		cout<<endl;
		cout<<"ID: "<<r3.robotId<<endl;
		cout<<"Type: "<<r3.robotype<<endl;
		cout<<"Battery: "<<r3.Battery<<endl;
		cout<<"Speed: "<<r3.speed<<endl;
		cout<<endl;
	}
}
