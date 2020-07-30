//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include <iostream>
using namespace std;

int main() 
{
	char ope; //character
	int number;
	bool solve = false;  
	cin >> number;
	int total = number;
	while (cin >> ope>> number )  //while loops
	{
		solve = false;
		if (!solve) 
		{			
			if (ope == '+') //operator
			{
				total += number; //total=number+total
				solve = true;
			}
			if (ope == ';') //if we put semicolon will print total
			{
				cout << total << endl; //prints total
				solve = true;
				total = number;
			}
			else if (ope == '-') //operator
			{
				total -= number;  //total=number-total
				solve = true; //solve equals true than will go solve.
			}
		}
	}
	
		cout <<total << endl;  //prints total

	return 0;
}