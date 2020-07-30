#include<iostream>
using namespace std;
class Rectangle {
	private:
		double x;
		double y;
public:
	Rectangle(double height, double width);
	double Perimeter();
	double Area();
	void resize(double m);

};
Rectangle::Rectangle(double height, double width)
{
	x = height;
	y = width;
}
double Rectangle::Perimeter()
{
	return 2*x + 2*y;
}
double Rectangle::Area()
{
	return x*y;
}
void Rectangle::resize(double m)
{
	x = x*m;
	y = y*m;
}

int main()
{
	Rectangle r(5, 10);

	cout << "perimeter of the rectangle is " << r.Perimeter() << endl;
	cout << "area of the rectangle is " << r.Area() << endl;
	r.resize(3);
	cout << "perimeter of the rectangle is " << r.Perimeter() << endl;
	cout << "area of the rectangle is " << r.Area() << endl;
}