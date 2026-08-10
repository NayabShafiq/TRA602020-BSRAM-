#include<iostream>
using namespace std;
const float PI = 3.14159f;
class Shape 
{
    protected:
	   float side;
	public:
       Shape(float s) : side(s) {}
       float calulateArea() 
	     {
	        return side * side;
		 } 
}; 
class Circle : public Shape
{
	public:
		Circle(float r) : Shape(r) {}
		float calulateArea()
		{
			return PI * side * side;
		}
};
class Rectangle : protected Shape
{
	public:
		Rectangle(float s) : Shape(s) {}
		float calulateArea()
		{
			return side * 2 * side;
		}
		float getArea()
		{
			return calulateArea();
		}
};
class Triangle : private Shape
{
	public:
		Triangle(float s) : Shape(s) {}
		float calulateArea()
		{
			return 0.5f * side * side;
		}
		float getArea()
		{
			return calulateArea();
		}
};
int main()
{
	Circle c(5.0f);
    Rectangle r(4.0f);
    Triangle t(6.0f);
    cout << "Circle Area : " << c.calulateArea() << endl;
    cout << "Rectangle Area : " << r.getArea() << endl;
    cout << "Triangle Area : " << t.getArea() << endl;
    cout << endl;
    cout << "=== Mode Observation ===" << endl;
    cout << "Public : calculateArea() callable directly from main." << endl;
    cout << "Protected: hidden from main - accessed via getArea() wrapper." << endl;
    cout << "Private : hidden from main - accessed via getArea() wrapper." << endl;
    return 0;
}



