//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void splitOnSpace(string s, string & before, string & after) {
	// reset strings
	before = "";
	after = "";
	// accumulate before space
	int i = 0;
	while (i < s.size() && !isspace(s[i])) {
		before = before + s[i];
		i++;
	}
	// skip the space
	i++;
	// accumulate after space
	while (i < s.size()) {
		after = after + s[i];
		i++;
	}
}
string Pronunciation(string word)
{
	string le = "", bef = "", aft = "";
	for (int i = 0; i < word.length(); i++)  // input donut = 4  if 0 <4 than 
	{
		if ((word[i] >= 'a') && (word[i] <= 'z'))   // if word[0]=d which is grater than a and less than z so 
		{
			word[i] = char((int)word[i] - 32);  // word[0]= word[0]-32         
		}
		le = le + word[i];
	}
	ifstream fin("cmudict.0.7a"); //opens just like lab 3 takes the data from a file 
	string line;
	if (fin.fail())        //if cannot open than prints the one in below 
	{
		cout << "File cannot be opened for reading." << endl;
		exit(1);
	}

	while (getline(fin, line))
	{
		splitOnSpace(line, bef, aft);
		if (le == bef)
		{
			return aft;
		}
	}
	fin.close(); //if searchs fin and cannot find something than result will be not found
	return "Not found";
}
void identical(string word,string pron)
{
	string W;
	for (int i = 0; i < word.length(); i++)
	{
		if ((word[i] >= 'a') && (word[i] <= 'z'))
		{
			word[i] = char((int)word[i] - 32);
		}
		W = W + word[i];
	}
	string dict_word, dict_pron;


	ifstream file("cmudict.0.7a");
	string line;

	while (getline(file, line))
	{
		splitOnSpace(line, dict_word, dict_pron);
		if (pron == dict_pron && dict_word != W)
		{
			cout << dict_word << " ";
		}
	}
	cout << endl;
	file.close();
}
void replacephenome(string word, string pron)
{
	string W;
	for (int i = 0; i < word.length(); i++)
	{
		if ((word[i] >= 'a') && (word[i] <= 'z'))
		{
			word[i] = char((int)word[i] - 32);
		}
		W = W + word[i];
	}
	string bf, aft, bf1, aft1, addp;
	ifstream file("cmudict.0.7a");
	string line;
	int fail = 0;
	while (getline(file, line))
	{
		splitOnSpace(line, bf, aft);
		addp = bf;
		splitOnSpace(aft, bf, aft);
		splitOnSpace(aft, bf, aft);
		splitOnSpace(pron, bf1, aft1);
		splitOnSpace(aft1, bf1, aft1);
		fail = 0;
		while (aft != "" || bf != "")
		{
			if (bf != aft1)
			{
				fail = fail + 1;
			}
			if (fail > 1)
			{
				break;
			}

			splitOnSpace(aft, bf, aft);
			splitOnSpace(aft1, bf1, aft1);
		}
			if (fail <= 1 && aft1 == "" && aft == "")
			{
				if (fail == 0 && addp != W)
				{
					cout << addp << " ";
				}
				else if (fail == 1 && bf == bf1)
				{
					cout << addp << " ";
				}
			}
		}
		cout << endl;
		file.close();

	}

int main()
{
	string word, result, result1;
	cout << "Enter something: " << endl;
	cin >> word;
	result = Pronunciation(word);
	cout << "Pronunciation: " << result << endl;
	cout << "Identical= "  << endl;
	identical(word, result);
	cout << "Replace phoneme" << endl;
	replacephenome(word, result);

}