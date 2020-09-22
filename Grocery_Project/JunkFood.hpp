#ifndef JunkFood_
#define JunkFood_
#include <iostream>
#include <string>
#include "Grocery.hpp"

class JunkFood : public Grocery
{
public:
	JunkFood(std::string name, double price, double weight);
	JunkFood();
	void updateCost();

};




#endif