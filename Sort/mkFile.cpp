//This file make files with random quantity numbers

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void MakeRandomNumber(ofstream &fout)
{
	int x;
	cout << "RAND_MAX = " << RAND_MAX << endl; // константа, хранящая максимальный предел из интервала случайных чисел
  for(int i = 0; i< 10000; i++)
  {	
  	x = rand();
  	cout << "random number = " << x << endl;
  	fout << x << endl;
	}
}

int main(int argc, char const *argv[])
{
	ofstream fout ("dFile.txt");
	fout << "Work with files" << endl;
	MakeRandomNumber(fout);
	fout.close();

	return 0;
}