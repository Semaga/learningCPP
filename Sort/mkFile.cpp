//This file make files with random quantity numbers

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void MakeRandomNumber(const string &fileName);



int main(int argc, char const *argv[])
{
	string fileName = "dRawFile.txt";
	MakeRandomNumber(fileName);

	return 0;
}

void MakeRandomNumber(const string &fileName)
{
	int x;
	ofstream input(fileName); //ofstream using for write to file
	if(input)
	{
		cout << "\tFile " << fileName << " is open ..." << endl;
		cout << "\t\tWrite to " << fileName << endl;
		for(int i = 0; i < 10000; i++)
  		input << rand() << " ";
		input.close();
		cout << "\tFile " << fileName << " was closed ..." << endl;
	}else
		cout << "\tError" << "\n\tfile " << fileName << " not found" << endl;
}