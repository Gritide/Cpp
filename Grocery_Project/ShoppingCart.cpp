//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<iomanip>
#include<string>
#include "ShoppingCart.hpp"
#include "Grocery.hpp"
#include "DynamicArray.hpp"


ShoppingCart::ShoppingCart()
{
	//DynamicArray<Grocery*>::~DynamicArray();
}

ShoppingCart::~ShoppingCart()
{
	//DynamicArray<Grocery*>::~DynamicArray();
}

bool ShoppingCart::add(Grocery *new_entry)
{
	resize();
	int crab = getIndexOf(new_entry);         //get the index of the item
	if (items_[crab] == new_entry)     //if input already exist
	{ 
		items_[item_count_] = new_entry;  //add item in the array
		new_entry->incrementQuantity();	// increment quantity
		curr_contents_weight_ = new_entry->getUnitWeight() + curr_contents_weight_; // update current weight
		return true;
	}
	else if (curr_contents_weight_ > 350)   // if our weight is greater than 350 stop adding
	{
		return false;
	}
	else
	{
		items_[item_count_] = new_entry;      //add item
		item_count_++;   //update item count
		curr_contents_weight_ = new_entry->getUnitWeight() + curr_contents_weight_;
		if (atCapacity()) //if we reach capacity
		{//call resize
			resize();
			return true;
		}
		return true;
	}
}

bool ShoppingCart::remove(Grocery*an_item)
{
	// resize();
	int z = an_item->getQuantity();           //quantity
	int index = getIndexOf(an_item);  //get the index of the item
	if (items_[index] == an_item&&z>0)//if input already exist
	{
		an_item->decrementQuantity();
		curr_contents_weight_ -= an_item->getUnitWeight(); //update current weight
		garbageClear(); //clear the item
		return true;
	}
	else
	{
		return false;
	}
	return true;

}

double ShoppingCart::checkout()
{
	if (item_count_ == 0)
	{
		std::cout << "Your cart is empty!" << std::endl;
		return 0;
	}

	double total = 0;
	for (size_t i = 0; i < item_count_; i++)
	{
		std::cout << "\n" << std::setw(10) << std::left <<
			items_[i]->getName() << "\t" << items_[i]->getQuantity()
			<< "\t" << std::fixed << std::setprecision(2)
			<< items_[i]->getTotalPrice();
		total += items_[i]->getTotalPrice();
	}
	std::cout << std::setfill('-') << std::setw(40) << "\n"
		<< std::endl << "Total:                  "
		<< total << std::endl << std::endl;
	clear();
	return total;
}

void ShoppingCart::garbageClear()
{
	int z = item_count_;
	for (int i = 0; i <z; i++)
	{
		if (items_[i]->getQuantity()==0)     //checks the all items in array and checks whether its quantity is 0
		{
			DynamicArray::remove(items_[i]);   //call remove 
		}
	}

}

double ShoppingCart::getCurrentWeight()
{

	return curr_contents_weight_;  //gets current weight
}
