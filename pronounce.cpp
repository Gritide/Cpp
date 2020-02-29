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
void identical(string word, string pron)
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
	string W = "";
	for (int i = 0; i < word.length(); i++) {
		if ((word[i] >= 'a') && (word[i] <= 'z')) {
			word[i] = char((int)word[i] - 32);
		}
		W = W + word[i]; //converting uppercase because our file only have uppercases.
	}

	string bf, aft, aft1, bf1, addp;
	ifstream file("cmudict.0.7a");
	string line;
	int fail = 0;
	while (getline(file, line))  //it will read all the lines. 
	{
		splitOnSpace(line, bf, aft);    //(accord, space,space)

		addp = bf;  //addp will be equal to bf we want to save it not to print save it again.
		splitOnSpace(aft, bf, aft);

		splitOnSpace(aft, bf, aft);
		splitOnSpace(pron, aft1, bf1);
		splitOnSpace(bf1, aft1, bf1);
		fail = 0;
		while (aft != "" || bf != "")   //after not equal space or before not equal space then
		{
			if (bf != aft1) //bf not eqaul after1
			{//then fail wll be 0+1 =1 
				fail = fail + 1;     //this will stop infinite loop 
			}
			if (fail > 1)
			{       //fail is 1 then leave from while loop
				break; //this will stop infinite loop 
			}

			splitOnSpace(aft, bf, aft);
			splitOnSpace(bf1, aft1, bf1);
			if (aft == "" || bf1 == "") //after spliting on the space if after is equal space or before1 equal space than 
										//leave from loopp.
			{
				break;
			}
		}
		if (fail <= 1 && bf1 == "" && aft == "")     //if fail<=1 and bf1 is space and aft is equal space 
		{
			if (fail == 0 && addp != W)       //if (fail is=0 and old word is not equal word 
											  //we dont want to print input word again.
			{
				cout << addp << " ";
			}
			if (fail == 1 && bf == aft1)
			{
				//fail is 1 and bf equals af1 then we will return old word
				cout << addp << " ";
			}

		}
	}

	cout << endl;
	file.close(); //closing cmudict.0.7a
}
void addPhoneme(string word, string pron)
{
	string W = "";
	for (int i = 0; i < word.length(); i++) {
		if ((word[i] >= 'a') && (word[i] <= 'z')) {
			word[i] = char((int)word[i] - 32);
		}
		W = W + word[i]; //converting uppercase because our file only have uppercases.
	}

	string bf, aft, aft1, bf1, addp;
	ifstream file("cmudict.0.7a");
	string line;
	int fail = 0;
	while (getline(file, line))  //it will read all the lines. 
	{
		splitOnSpace(line, bf, aft);    //(accord, space,space)

		addp = bf;  //addp will be equal to bf we want to save it not to print save it again.
		splitOnSpace(aft, bf, aft);

		splitOnSpace(aft, bf, aft);
		splitOnSpace(pron, aft1, bf1);
		splitOnSpace(bf1, aft1, bf1);
		fail = 0;
		//Comapre the phenomes of the two word one by one.
		//If the pronounciation of the current word has
		//only one extra phenome then display the current word.
		while (aft != "" || bf != "") 
		{
			if (bf == aft1)
			{
				splitOnSpace(bf1, aft1, bf1);
				if (aft1 == "")
				{
					while (aft != "")
					{
						splitOnSpace(aft, bf, aft);
						fail = fail + 1;
					}
					splitOnSpace(aft, bf, aft);
				}
				else 
				{
					splitOnSpace(aft, bf, aft);
				}
			}
			else 
			{
				fail++;
				splitOnSpace(aft, bf, aft);
				if (fail == 1 && aft == "") {
					fail = 2;
					break;
				}
			}
		}
		bf = "";
		aft = "";
		if (fail == 1 && bf1 == "") //reseting word
		{
			cout << addp << " ";
		}
	}
	cout << endl;
	//Close the file.
	file.close();
}
int main()
{
	string word, result, result1;

	cout << "Enter something: " << endl;
	cin >> word;
	result = Pronunciation(word);
	cout << "Pronunciation: " << result << endl;
	cout << "Identical: ";
	identical(word, result);
	cout << "Replace phoneme: ";
	replacephenome(word, result);
	cout << "Add phoneme: ";
	addPhoneme(word, result);

}