#include<iostream>
#include<fstream>
using namespace std;
struct Robot
{
	int Sensor_ID;
	float Temperature;
	float Distance_cm;
	string Timestamp;
};
int main()
{
	Robot r[3]={{1, 12.3, 12.0, "10AM"},
	            {2, 10.2, 15.3, "11AM"},
				{3, 15.0, 10.6, "12PM"}};
	ofstream file("sensor_log.txt");
	for(int i=0;i<3;i++)
	{	
	    file<<r[i].Sensor_ID<<" "
	        <<r[i].Temperature<<" "
	        <<r[i].Distance_cm<<" "
	        <<r[i].Timestamp<<endl;
    }
    file.close();
	ifstream fin("sensor_log.txt");
	cout<<"\n===Sensor Reading===\n";
	for(int i=0;i<3;i++)
	{
		
	    fin>>r[i].Sensor_ID
		   >>r[i].Temperature
	       >>r[i].Distance_cm
	       >>r[i].Timestamp;
	    
	    cout<<"\n---Sensor "<<i+1<<"---"<<endl;
	    cout<<"\nSensor ID: "<<r[i].Sensor_ID<<endl;
	    cout<<"Temperature: "<<r[i].Temperature<<endl;
	    cout<<"Distance in cm: "<<r[i].Distance_cm<<endl;
	    cout<<"Timestamp: "<<r[i].Timestamp<<endl;
    }
	fin.close();
}
