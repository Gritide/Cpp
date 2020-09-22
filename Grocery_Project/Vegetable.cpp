#include<iostream>
#include "Vegetable.hpp"
#include "Grocery.hpp"
using namespace std;

Vegetable::Vegetable(std::string name, double price, double weight) : Grocery(name,price,weight)
{
	weight = price*weight;
	total_price_ = price*weight;

}


void Vegetable::updateCost()
{	
	
	total_price_;
}

