//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#ifndef JunkFood_
#define JunkFood_
#include <iostream>
#include <string>
#include "Grocery.hpp"

class JunkFood : public Grocery //JF is child grocery is the parent class
{
public:
	JunkFood(std::string name, double price, double weight); 
	void updateCost(); //virtual

};
#endif