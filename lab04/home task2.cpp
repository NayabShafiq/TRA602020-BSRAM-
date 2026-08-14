#include<iostream>
using namespace std;
struct Parameters
{
	float length; 
	float width;
};
struct Result
{
	float area;
	float parameter;
};
struct rectangle
{
	Parameters p;
	Result r;
};
int main()
{
	rectangle rec;
	cout<<"Enter length: ";
	cin>>rec.p.length;
	cout<<"Enter width: ";
	cin>>rec.p.width;
	rec.r.area = rec.p.length * rec.p.width;
	rec.r.parameter = 2 *(rec.p.length + rec.p.width);
	cout<<"\t===Rectangle Result===\n";
	cout<<"Area: "<<rec.r.area<<endl;
	cout<<"Parameter: "<<rec.r.parameter<<endl;
	return 0;
}
