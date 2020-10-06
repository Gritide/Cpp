//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<string>
#include"JunkFood.hpp"
JunkFood::JunkFood(std::string name, double price, double weight) :Grocery(name, price, weight)  //constructor
{
	name_ = name;
	unit_price_ = price;
	unit_weight_ = weight;
	//get name price and weight 
}
void JunkFood::updateCost()
{
	total_price_ = unit_price_*quantity_;
}