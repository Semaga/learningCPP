//This file make files with random quantity numbers

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void MakeRandomNumber(const string &fileName)
{
	int x;
	ofstream input(fileName); //ofstream using for write to file
	if(input)
	{
		for(int i = 0; i < 10000; i++)
  	{		
  		x = rand();
  		cout << "random number = " << x << endl;
  		input << x << endl;
		}	
		input.close();
	}else
		cout << "\tError" << "\n\tfile " << fileName << " not found" << endl;
}

int main(int argc, char const *argv[])
{
	string fileName = "dRawFile.txt";
	MakeRandomNumber(fileName);

	return 0;
}