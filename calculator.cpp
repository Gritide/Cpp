#include<iostream>
using namespace std;
int main()
{
	int number = 0, tt = 0;
	char pp, pp_1;
	cin >> number;
	while (cin >> pp)
	{
		if (pp == '^')
		{
			number = number*number;
			cin >> pp;
		}
		if (pp_1 = '+')
		{
			tt += number;
		}
		else if (pp_1 == '-')
		{
			tt -= number;
		}
		pp_1 = pp;
		cin >> number;
		if (pp_1 == ';')
		{
			cout << tt << endl;
			tt = 0;
			pp_1 = '+';
		}
	}
}