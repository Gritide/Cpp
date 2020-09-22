#ifndef ShoppingCart_
#define ShoppingCart_
#include<iostream>
#include "DynamicArray.hpp"
#include "Grocery.hpp"
#include<string>



//template<class T>
class ShoppingCart :public DynamicArray<Grocery*>
{
public:
	ShoppingCart();
	~ShoppingCart();
	bool add(Grocery * new_entry);
	bool remove(Grocery * an_item);
	double checkout();
	void garbageClear();
	double getCurrentWeight();

private:
	double curr_contents_weight_;



};
//#include"ShoppingCart.cpp"
//#include"DynamicArray.cpp"




#endif