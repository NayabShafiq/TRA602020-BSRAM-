#include<iostream>
#include<string>
using namespace std;
class Animal
{
	protected:
		string name; 
		string species;
	public:
		Animal(string n, string s)
		: name(n), species(s)
		{}
		void sound()
		{
			cout<<"Animals make sound : "<<endl;
		}
		void describe()
		{
			cout<<"Name: "<<name<<" | Species: "<<species<<endl;
		}
};
class Cat : public Animal
{
	private:
		string breed;
	public:
		Cat(string n, string s, string b)
		: Animal(n, s), breed(b)
		{}
		void sound()
		{
			cout<<"Sound: Meow! Meow!"<<endl;
		}
		void describe()
		{
			Animal::describe();
			cout<<"Breed: "<<breed<<endl;
		}
};
class Dog : public Animal
{
	private:
		string breed;
	public:
		Dog(string n, string s, string b)
		: Animal(n, s), breed(b)
		{}
		void sound()
		{
			cout<<"Sound: Woof! Woof!"<<endl;
		}
		void describe()
		{
			Animal::describe();
			cout<<"Breed: "<<breed<<endl;
		}
};
class GuardDog : public Dog
{
	private:
		int trainingLevel;
	public:
		GuardDog(string n, string s, string b, int t)
		: Dog(n,s,b), trainingLevel(t)
		{}
		void sound()
		{
			cout<<"Sound: Woof!Woof!Stay!Back: "<<endl;
		}
		void describe()
		{
			Dog::describe();
			cout<<"Training level: "<<trainingLevel<<endl;
		}
};
int main()
{
	Cat c("Whiskers", "Feline", "Persian");
	Dog d("Bruno", "Canine", "German Shepherd");
	GuardDog g("Rex", "Canine", "Rottweiler", 5);
	cout<<"=== Cat ==="<<endl;
	c.describe();
	c.sound();
	cout<<endl;
	cout<<"=== Dog ==="<<endl;
	d.describe();
	d.sound();
	cout<<endl;
	cout<<"=== Guard Dog ==="<<endl;
	g.describe();
	g.sound();
	cout<<endl;
	cout<<"Base Dog sound via scope resolution: ";
    g.Dog::sound();
    return 0;
}
	
	

