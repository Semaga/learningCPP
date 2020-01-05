//This file make files with random quantity numbers

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

vector <string> split (string &s, char delimiter = ' ');
void WriteRandomNumber(const string &fileName);
void DoSortFromFile(const string &fileName, vector &v);

int main(int argc, char const *argv[])
{
	string fileName = "dRawFile.txt";
	WriteRandomNumber(fileName);
	vector<int> v;
	return 0;
}

vector <string> split (string &s, char delimiter = ' ')
{
	stringstream ss(s);
	string item;
	vector <string> tokens;
	while (getline(ss,item, delimiter))
		tokens.push_back(item);
	return tokens;
}


void WriteRandomNumber(const string &fileName)
{
	ofstream fout(fileName); //ofstream using for write to file
	if(fout)
	{
		cout << "\tFile " << fileName << " is open ..." << endl;
		cout << "\t\tWrite to " << fileName << endl;
		for(int i = 0; i < 10000; i++)
  		fout << rand() << " ";
		fout.close();
		cout << "\tFile " << fileName << " was closed ..." << endl;
	}else
		cout << "\tError" << "\n\tfile " << fileName << " not found" << endl;
}

void DoSortFromFile(const string &fileName, vector &v)
{
	ifstream fin(fileName); //
	if(fin)
	{
		string line;
		getline(fin, line);

	}else
		cout << "\tError" << "\n\tfile " << fileName << " not found" << endl;
}
