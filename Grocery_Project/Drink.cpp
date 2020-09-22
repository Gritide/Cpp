#include<iostream>
#include"Grocery.hpp"
#include"Drink.hpp"



Drink::Drink(std::string name, double price, double weight) :Grocery(name, price, weight)
{
	double Floz = 33.814;
	weight = weight * 16 / Floz;
	price = price*weight;
	total_price_ = price*4;
}
void Drink::updateCost()
{
	total_price_;
}
