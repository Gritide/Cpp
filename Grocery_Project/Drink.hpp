//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#ifndef Drink_
#define Drink_
#include <iostream>
#include <string>
#include "Grocery.hpp"

class Drink : public Grocery //drink is child grocery is the parent class
{
public:
	Drink(std::string name, double price, double weight);
	//Drink();
	void updateCost(); //virtual
};
#endif