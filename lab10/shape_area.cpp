#include<iostream>
#include<string>
using namespace std;
const float PI = 3.14159f;
class shape
{
	protected:
		string shapeName;
	public:
		shape(string name) : shapeName(name) 
		{}
		float calculateArea()
		{
		   return 0.0f;
		}
	    void describe() 
		{
			cout<<"I am a shape called : "<<shapeName<<endl;
		}
};
class Rectangle : public shape
{
	private:
		float length;
		float width;
	public:
		Rectangle(string n, float l, float w) 
		: shape(n), length(l), width(w)
		{}
		float calculateArea()
		{
			return length * width;
		}
		void describe()
		{
			shape::describe();
			cout<<"Type : Rectangle | length: "<<length
			    <<" | width: "<<width<<endl;
		}
};
class Circle : public shape
{
	private:
		float radius;
	public:
		Circle(string n, float r) 
		: shape(n), radius(r)
		{}
		float calculateArea()
		{
			return PI * radius * radius;
		}
		void describe()
		{
			shape::describe();
			cout<<"Type : Circle | radius: "<<radius<<endl;
		}
};
int main()
{
	Rectangle r("Rectangle", 6.0f, 4.0f);
	Circle c("Circle", 5.0f);
	r.describe();
    cout<<"Area: "<<r.calculateArea()<<endl<<endl;
    c.describe();
    cout<<"Area: "<<c.calculateArea()<<endl;
    return 0;
}

