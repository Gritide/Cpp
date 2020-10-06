//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#ifndef Vegetable_
#define Vegetable_
#include <iostream>
#include <string>
#include "Grocery.hpp"

class Vegetable: public Grocery //vegetable is child grocery is the parent class (derived)
{
public:
	 Vegetable(std::string name, double price, double weight);
	void updateCost(); //virtual

};
#endif