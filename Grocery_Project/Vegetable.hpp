
#ifndef Vegetable_
#define Vegetable_
#include <iostream>
#include <string>
#include "Grocery.hpp"

class Vegetable: public Grocery
{
public:
	 Vegetable(std::string name, double price, double weight);
	 Vegetable();
	void updateCost();

};





#endif