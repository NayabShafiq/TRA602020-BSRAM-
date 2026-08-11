#include<iostream>
#include<string>
using namespace std;
class AIModel
{
	public:
		string modelName;
		string version;
		string algorithm;
		float accuracy;
		bool isDeployed;
};
int main()
{
	AIModel m1,m2,m3;
	m1.modelName="RestNet-50";
	m1.version="v2.1";
	m1.algorithm="CNN";
	m1.accuracy=0.56;
	m1.isDeployed=true;
	
	m2.modelName="SVM-classifeir";
	m2.version="v2.0";
	m2.algorithm="CNN";
	m2.accuracy=0.56;
	m2.isDeployed=false;
	
	m3.modelName="YOLOv5";
	m3.version="v3.1";
	m3.algorithm="CNN";
	m3.accuracy=0.78;
	m3.isDeployed=true;
	
	cout<<"---AI MODEL CARD---"<<endl;
	cout<<"Name: "<<m1.modelName<<endl;
	cout<<"Version: "<<m1.version<<endl;
	cout<<"Algorithm: "<<m1.algorithm<<endl;
	cout<<"Accuracy: "<<m1.accuracy<<endl;
	cout<<"Deployed: "<<m1.isDeployed<<endl;
	cout<<"Name: "<<m2.modelName<<endl;
	cout<<"Version: "<<m2.version<<endl;
	cout<<"Algorithm: "<<m2.algorithm<<endl;
	cout<<"Accuracy: "<<m2.accuracy<<endl;
	cout<<"Deployed: "<<m2.isDeployed<<endl;
	cout<<"Name: "<<m3.modelName<<endl;
	cout<<"Version: "<<m3.version<<endl;
	cout<<"Algorithm: "<<m3.algorithm<<endl;
	cout<<"Accuracy: "<<m3.accuracy<<endl;
	cout<<"Deployed: "<<m3.isDeployed<<endl;
}
