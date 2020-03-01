//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<vector>
using namespace std;
vector<int> merge_sorted(vector<int> a, vector<int> b) 
{
	int i = 0, j = 0;
	int a1 = a.size();
	int b1 = b.size();
	vector<int> c;
	while (i < a1 && j < b1)
	{
		if (a[i] < b[j])
		{
			c.push_back(a[i]);
			i++;
		}
		else
		{
			c.push_back(b[j]);
			j++;
		}
	}
	while(i<a1)
	{
		c.push_back(a[i]);
		i++;
	}
	while (j < b1) 
	{
		c.push_back(b[j]);
		j++;
	}
	return c;
}
int main()
{
	vector<int> a = { 1,4,9,16 };
	vector<int> b = { 4,7,9,9,11 };
	vector<int> cs= merge_sorted(a, b);
	for (int i = 0; i < cs.size(); i++)
	{
		cout << cs[i] << " ";
	}
	cout << endl;
}