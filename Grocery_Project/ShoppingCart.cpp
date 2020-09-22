#include<iostream>
#include<iomanip>
#include "ShoppingCart.hpp"
#include "Grocery.hpp"
#include "DynamicArray.hpp"

//using namespace std;
//template <class T>
ShoppingCart::ShoppingCart() {}

//template <class T>
ShoppingCart::~ShoppingCart()
{

}

//template <class T>.
/**
adds new_entry to the caller; if the entry
already exists in the caller, increment
quantity_ in the object, and increment
the curr_contents_weight_ of the caller
by the unit_weight_ of the added item.

@pre    :   the addition of the weight of
new_entry does not bring the
curr_contents_weight_ over the
carrying capacity

@return :   true if the addition is successful
*/
bool ShoppingCart::add(Grocery *new_entry) 
{
	int z = item_count_;
	for (int i = 0; i <z; i++)
	{
		if (items_[i] == new_entry)
		{
			//quantity_++;
			curr_contents_weight_;//= unit_weight_ + curr_contents_weight_;
			return true;
		}
		else if (curr_contents_weight_ > 365)
		{
			return false;
		}
		else
		{
			curr_contents_weight_;//= unit_weight_ + curr_contents_weight_;
			return true;
		}
	}
	return true;
	
}
//template <class T>
 bool ShoppingCart::remove(Grocery*an_item)
{
	 int n = item_count_;
	for (int i = 0; i < n; i++)
	{
		if (items_[i] = an_item)
		{
			//quantity_--;
			//curr_contents_weight_ = curr_contents_weight_ - unit_weight_;
			garbageClear();
			return true;
		}
		else
			return false;
	}
	return true;
}

 
//template <class T>
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
//template <clas
void ShoppingCart::garbageClear()
{
	//DynamicArray<Grocery*>::remove();
}





//template <class T>
double ShoppingCart::getCurrentWeight()
{
	return curr_contents_weight_;
}

