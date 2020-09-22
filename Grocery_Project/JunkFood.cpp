#include<iostream>
#include<string>
#include"JunkFood.hpp"
#include"Grocery.hpp"


JunkFood::JunkFood(std::string name, double price, double weight) :Grocery(name, price, weight)
{

	weight = 12 * weight;
	total_price_ = price*weight;
}
void JunkFood::updateCost()
{
	total_price_;
}