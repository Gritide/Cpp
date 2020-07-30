//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include <iostream>
#include <string>
using namespace std;
string reverse(string str)
{
	
	int i = 0;
	if (i == str.length())     //checks whether we enter something or not
	{
		return "";
	}
	else
	{
		//string ded = reverse(str.substr(1)) + str[0];
		return reverse(str.substr(1)) + str[0];      //returning recursive function.
		//return ded;   
	} //reversing ;
	//flow take out f add 
	//low take ouf l add 
	//ow take out o add 
	//w take out w add 
}


int main()
{
	string input;
	cin >> input;
	cout << "the word is " << input << endl;
	cout << "after reversing " << reverse(input) << endl;
	return 0;
}
