//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<vector>
using namespace std;
vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2)
{
	vector<int> cs;
	int max = v1.size(); //3
	if (max <= v2.size())
	{
		max = v2.size();// max=2
	}
		int sum;
		for (int i = 0; i < max; i++)  // i<3
		{
			sum = 0;
			if (i < v1.size())   //if i less than v1 size  
			{
				sum = sum + v1[i];  //we will add                     sum=1        sum=2     sum=3
			}
			if (i < v2.size())  //if i less than v2 size 
			{
				sum = sum + v2[i];   //we will add					=sum=5              sum=7   cannot do 3 i =2 2<2 we skip this part    so sum 3
			}
			cs.push_back(sum);     //new vector     5,7,3
		}
		return cs; //returns new vector
}
int main()
{
	vector<int> v1{ 1,2,3 };
	vector<int> v2{ 4,5 };
	vector<int> csz = sumPairWise(v1, v2); // returns [5, 7, 3]
	for (int i = 0; i<csz.size(); i++)
	{
		cout << csz[i] << " ";
	}
	cout << endl;
	return 0;
}

