#include<iostream>
using namespace std;
class Chef
{
public:
	virtual void makeChicken();
	void makeSalad();
};

void Chef::makeChicken()
{
	cout << "This chef makes chicken" << endl;
}
void Chef::makeSalad()
{
	cout << "This chef makes salad" << endl;
}

class italianCheft :public Chef
{
public:
	void makeItalianDish();
};

void italianCheft::makeItalianDish()
{
	cout << "This chef makes italian food" << endl;
}

int main()
{
	Chef f;
	f.makeChicken();

	italianCheft i_f;
	i_f.makeItalianDish();
	i_f.makeChicken();
}