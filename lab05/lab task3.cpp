#include<iostream>
using namespace std;
struct PetrolPump
{
	char name[20];
	float pricePerLiter;
	int availableLiters;
};
void input(PetrolPump*p)
{
	cout<<"Enter Pump Name: ";
	cin>>p->name;
	cout<<"Enter Price per Liter: ";
	cin>>p->pricePerLiter;
	cout<<"Enter Available Liters: ";
	cin>>p->availableLiters;
}
void display(PetrolPump*p)
{
	cout<<"\n---Petrol Pump Record---\n";
	cout<<"Enter Pump Name: "<<p->name<<endl;
	cout<<"Enter Price per Liter: "<<p->pricePerLiter<<endl;
	cout<<"Enter Available Liters: "<<p->availableLiters<<endl;
}
int main()
{
	PetrolPump p;
	PetrolPump*ptr=&p;
	input(ptr);
	display(ptr);
	return 0;
}
