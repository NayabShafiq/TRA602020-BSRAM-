#include<iostream>
#include<fstream>
using namespace std;
struct SensorReading
{
	int sensorID;
	float temperature;
	float humidity;
	string timestamp;
};
int main()
{
	SensorReading s[3]={
	{1,36.5,72.3,"2024-01-15 08:00"},
	{2,38.1,68.9,"2024-01-15 08:05"},
	{3,35.7,75.1,"2024-01-15 08:10"}
	};
	ofstream file("sensor_log.txt");
	if(!file)
	{
		cout<<"Error in creating file"<<endl;
		exit(1);
	}
	for(int i=0;i<3;i++)
	{
		file<<"--- Sensor Reading "<<(i+1)<<" ---"<<endl;
		file<<"Sensor ID: "<<s[i].sensorID<<endl;
		file<<"Temperature: "<<s[i].temperature<<endl;
		file<<"Humidity: "<<s[i].humidity<<endl;
		file<<"Timestamp: "<<s[i].timestamp<<endl;
	}
	file.close();
	cout<<"File sensor_log.txt created successfully."<<endl;
	ifstream readfile("sensor_log.txt");
	string line;
	if(!readfile)
	{
		cout<<"Error in opening file"<<endl;
		exit(1);
	}
	cout<<"\nReading file contents:\n";
	while(getline(readfile,line))
	{
		cout<<line<<endl;
    }
		readfile.close();	
		return 0;
}
