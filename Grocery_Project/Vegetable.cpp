//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<string>
#include "Vegetable.hpp"
#include "Grocery.hpp"


Vegetable::Vegetable(std::string name, double price, double weight) : Grocery(name,price,weight)   //constructor
{ 
	name_ = name;
	unit_price_ = price;
	unit_weight_ = weight;
	updateCost();   
	//get name price and weight 
}


void Vegetable::updateCost()
{	
	
	total_price_ = unit_price_*quantity_*unit_weight_; //total price 
}

