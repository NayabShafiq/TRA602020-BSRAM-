#include<iostream>
#include<string>
using namespace std;
class Sensor
{
	public:
	string sensorId; 
	string sensorType;
	int reading;
    bool isActive;
};
int main()
{
	Sensor s1,s2,s3;
	s1.sensorId="S-001";
	s1.sensorType="Ultrasonic";
	s1.reading=25.4;
	s1.isActive=true;
	
	s2.sensorId="S-002";
	s2.sensorType="Infrared";
	s2.reading=45.5;
	s2.isActive=true;
	
	s3.sensorId="S-003";
	s3.sensorType="Camera";
	s3.reading=38.4;
	s3.isActive=false;
	
	cout<<"---Sensor status---"<<endl;
	cout<<boolalpha;
	cout<<"ID: "<<s1.sensorId<<endl;
	cout<<"Type: "<<s1.sensorType<<endl;
	cout<<"reading: "<<s1.reading<<endl;
	cout<<"Active: "<<s1.isActive<<endl;
	cout<<endl;
	cout<<"ID: "<<s2.sensorId<<endl;
	cout<<"Type: "<<s2.sensorType<<endl;
	cout<<"reading: "<<s2.reading<<endl;
    cout<<"Active: "<<s2.isActive<<endl;
    cout<<endl;
	cout<<"ID: "<<s3.sensorId<<endl;
    cout<<"Type: "<<s3.sensorType<<endl;
	cout<<"reading: "<<s3.reading<<endl;
	cout<<"Active: "<<s3.isActive<<endl;
}
