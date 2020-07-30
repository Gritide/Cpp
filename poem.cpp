//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<string>
using namespace std;
string * createAPoemDynamically() 
{
	string *p = new string;
	*p = "Roses are red, violets are blue"; //poem
	return p;
}

int main() 
{
	while (true) 
	{
		string *p;
		p = createAPoemDynamically();    //calling function     
		// assume that the poem p is not needed at this point
		if (!p)          //if p is not true than failes.
		{
			//cout << "failed"<< endl;
		}
		cout << *p << endl;     //prints out infinite  poem 
		delete p;      //deletes
	}
	
}