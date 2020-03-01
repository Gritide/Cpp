//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
using namespace std;

class Rectangle {
private:
	double height;
	double width;
public:
	Rectangle(double input_w, double input_h) // I tried to put outside of class but couldnt work than I tried to put in class It worked/
	{
		width = input_w;
		height = input_h;
	}
	double get_perimeter();
	double get_area();
	void resize(double factor);

};

void Rectangle::resize(double factor)     //resize rectangle
{
	width = width*factor;
	height = height*factor;
}
double Rectangle::get_perimeter()
{
	return 2 * width + 2 * height;
}

double Rectangle::get_area()
{
	return width*height;
}
int main()
{	
	Rectangle r(5,10);
	cout << "Perimeter of rectangle is " << r.get_perimeter() << endl;
	cout << "Area of rectangle is " << r.get_area() << endl;
	//cout << "Factor " << r.resize();
	r.resize(3);
	cout << "Perimeter of rectangle is " << r.get_perimeter() << endl;
	cout << "Area of rectangle is " << r.get_area() << endl;
}
