
//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<string>
#include<iostream>
using namespace std;
void printRange(int left, int right)
{
	if (left>right) //if left is greater than right 			
	{
		return; //print nothing 
	}
	else if (left <= right) // if left less than equal to right 
	{
		cout << left << " ";
		printRange(left + 1, right); //print left ,left+1 to the right  
									 //in our case it will go -2 to 10
	}


}
int sumRange(int left, int right)
{
	if (left>right)    // if we input left less than right 
					   //return 0
	{
		return 0;
	}
	else
	{
		int z = left; //z equals left 
		z = z + sumRange(left + 1, right);//6//1,3              // we will add left to recursive function           //x=1,3         1+2=3       3+3=6
										  //y=-2,10   -2+-1=-3      -3+0=-3   -3+1=-2  -2+2=0     0+3=3  3+4=7  7+5=12 12+6=18      18+7=25  25+8=33   33+9=42  42+10=52 
		return z;
	}
}
int sumArrayInRange(int *arr, int left, int right)
{
	if (left>right)   //if left less is greater than right 
	{//return none;
		return 0;
	}
	else
	{
		return (arr[left] + sumArrayInRange(arr, left + 1, right)); //recursion
	}            //arr[0]+arr[1]=29         20+arr[20]=15 and so on
}
int sumArray(int *arr, int size)
{
	return sumArrayInRange(arr, 0, size - 1); //set left[0] arr  is all array and size will be size -1 we have 10 elements but arr[9] is  last.
}
bool isAlphanumeric(string s)
{

	if (s == "")
	{
		return true;
	}
	else
	{
		char first = s[0];
			if (isdigit(first) || isalpha(first)) //if first character is a number OR first character is a alphabetic return;
			{
				return isAlphanumeric(s.substr(1)); //return recursion function       //it takes all characters each runing 
			}
			else
			{
				return false;
			}
		}
	
	}
bool nestedParens(string s)
{

	if (s == "")
	{
		return true;
	}
	else if (s.length() < 2)
	{
		return false; // that means we can not have something less than 2 
	}
	else
	{
		if (s[0] == '(' && s[s.size() - 1] == ')') 
			//if we have ( in first character and last character should have )
		{
			return nestedParens(s.substr(1, s.size() - 2)); //checks all elements from second element 
			//to the last elements //checks body part.
		}
		else
		{
			return false;
		}
	}
}


bool solvable(int alice, int bob, int *prices, int size)
{
	if (size == 0) 
	{
		return (alice == bob); //if both sum are equal
	}
	if (solvable(alice + prices[0], bob, prices + 1, size - 1)) //for alice 
	{
		cout << prices[0] << "= Alice"<< endl;
		return true;
	}           //recursion
	if (solvable(alice, bob + prices[0], prices + 1, size - 1)) //for bob
	{
		cout << prices[0] << "= Bob" << endl;
		return true;
	}
	return false;
}
bool divisible(int *prices, int size)
{
	return solvable(0, 0, prices, size);
}

int main()
{

	/*int size = 10;
	int *arr = new int[size]; // allocate array dynamically
	arr[0] = 12;
	arr[1] = 17;
	arr[2] = -5;
	arr[3] = 3;
	arr[4] = 7;
	arr[5] = -15;
	arr[6] = 27;
	arr[7] = 5;
	arr[8] = 13;
	arr[9] = -21;

	int sum1 = sumArray(arr, size); // Add all elements
	cout << "Sum is " << sum1 << endl;  // Sum is 43

	int sum2 = sumArray(arr, 5); // Add up first five elements
	cout << "Sum is " << sum2 << endl;  // Sum is 34

	delete[] arr;   */      // deallocate it
	/*cout << isAlphanumeric("ABCD") << endl;        // true (1)
	cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
	cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)   */    
	/*cout << nestedParens("((()))") << endl;      // true (1)
	cout << nestedParens("()") << endl;          // true (1)
	cout << nestedParens("") << endl;            // true (1)

	cout << nestedParens("(((") << endl;         // false (0)
	cout << nestedParens("(()") << endl;         // false (0)
	cout << nestedParens(")(") << endl;          // false (0)
	cout << nestedParens("a(b)c") << endl;  */
	// false (0)//it will return false once recursion function sees " " returns false;
	int prices[] = { 10, 15, 12, 18, 19, 17, 13, 35, 33 };
	bool result;

	cout << "{10, 15, 12, 18, 19, 17, 13, 35, 33 }" << endl;
	cout << "divisible= " << divisible(prices, 9) << endl;
	return 0;
	return 0;

}
