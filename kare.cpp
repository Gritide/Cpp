#include<iostream>
using namespace std;
class Square {
private:
	double length;
public:
	Square(double input_length);
	double perimeter();
	double area();
	void resize(double m);
};
Square::Square(double input_length)
{
	length = input_length;

}
double Square::perimeter()
{
	return 4 * length;
}
double Square::area()
{
	return pow(length, 2);
}
void Square::resize(double m)
{
	length = length*m;
}
int main()
{
	Square r(5);
	cout << "perimeter of the rectangle is " << r.perimeter() << endl;
	cout << "area of the rectangle is " << r.area() << endl;
	r.resize(3);
	cout << "perimeter of the rectangle is " << r.perimeter() << endl;
	cout << "area of the rectangle is " << r.area() << endl;
}