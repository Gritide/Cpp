
#ifndef Drink_
#define Drink_
#include <iostream>
#include <string>
#include "Grocery.hpp"

class Drink : public Grocery
{
public:
	Drink(std::string name, double price, double weight);
	Drink();
	void updateCost();
};




#endif