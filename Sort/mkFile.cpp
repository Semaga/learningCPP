//This file make files with random quantity numbers

#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ofstream fout ("dFile.txt");
	fout << "Work with files" << endl;
	fout.close();

	return 0;
}