//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<string>
#include"Drink.hpp"

Drink::Drink(std::string name, double price, double weight) :Grocery(name, price, weight) //constructor
{
	name_ = name;
	unit_price_ = price;
	unit_weight_ = weight;
	//get name price and weight 
}
void Drink::updateCost()  //updatecost
{
	double weight =unit_weight_* 16 / 33.814; //new weight converting
	total_price_ = unit_price_ * quantity_*weight;
}
