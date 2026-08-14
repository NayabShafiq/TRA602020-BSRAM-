#include<iostream>
#include<string>
using namespace std;
struct Date
{
	int day;
	int month;
	int year;
};
struct Doctor
{
	string name;
	string specialization;
};
struct Patient
{
	string patientID;
	string name;
	int age;
	Date admissionDate;
	Doctor assignedDoctor;
	double dailyCharge;
};
double calculateBill(Patient p, int days)
{
	return p.dailyCharge*days;
}
void displayPatientReport(Patient p, int days)
{
	double totalBill = calculateBill(p,days);
	cout<<"\t===Hospital Bill===\n";
	cout<<"patient ID: "<<p.patientID<<endl;
	cout<<"Name: "<<p.name<<endl;
	cout<<"Age: "<<p.age<<endl;
	cout<<"Admission: "<<p.admissionDate.day<<"/"<<p.admissionDate.month<<"/"<<p.admissionDate.year<<endl;
	cout<<"Doctor: "<<p.assignedDoctor.name<<endl;
	cout<<"Specialization: "<<p.assignedDoctor.specialization<<endl;
	cout<<"\t--------------------\n";
	cout<<"Days Admitted: "<<days<<endl;
    cout<<"Daily Charge : Rs. "<<p.dailyCharge<<endl;
    cout<<"TOTAL BILL   : Rs. "<< totalBill<<endl;
    cout<<"\t=============================\n";
}
int main()
{
    Patient p1, p2;
    p1.patientID = "HOS-2024-001";
    p1.name = "Hamza Iqbal";
    p1.age = 45;
    p1.admissionDate = {10, 3, 2024};
    p1.assignedDoctor.name = "Dr. Asim Raza";
    p1.assignedDoctor.specialization = "Cardiology";
    p1.dailyCharge = 3500;
    p2.patientID = "HOS-2024-002";
    p2.name = "Fatima Zahra";
    p2.age = 30;
    p2.admissionDate = {15, 3, 2024};
    p2.assignedDoctor.name = "Dr. Nadia Khan";
    p2.assignedDoctor.specialization = "Orthopedics";
    p2.dailyCharge = 2800;
    displayPatientReport(p1, 5);
    displayPatientReport(p2, 3);
    return 0;
}
