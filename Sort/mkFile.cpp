//This file make files with random quantity numbers

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

template <typename T>
void PrintVec(vector <T> &v);
vector <string> split (string &s, char delimiter);
void WriteRandomNumber(const string &fileName);
void DoSortFromFile(const string &ReadFileName, const string &WriteFileName, vector <int> &data);

int main(int argc, char const *argv[])
{
	string RawFile = "dRawFile.txt";
	string SortData = "SortData.txt";
	WriteRandomNumber(RawFile);
	vector<int> mData;
	DoSortFromFile(RawFile, SortData, mData);
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

template <typename T>
void PrintVec(vector <T> &v)
{
	cout << "PrintVec:" << endl;
	cout << "\t" << endl;
	for(const auto &i:v)
	{
		cout << fixed;
		cout.precision(7);
		cout << i << ' ';
	}
	cout << endl;
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

void DoSortFromFile(const string &ReadFileName, const string &WriteFileName, vector <int> &data)
{
	ifstream fin(ReadFileName); //
	ofstream fout(WriteFileName);
	if(fin)
	{
		cout << "\tFile " << ReadFileName << " is open ... " << endl;
		cout << "\t\tRead from " << ReadFileName << endl;

		string line;
		vector<string> v;
		getline(fin, line);
		fin.close();
		v = split(line);
		for (auto &i:v)
		{
			data.push_back(stoi(i));
		}
		PrintVec(data);
		sort(data.begin(), data.end());
		PrintVec(data);
	}else
		cout << "\tError" << "\n\tfile " << ReadFileName << " not found" << endl;

		if (fout){
			cout << "\tFile " << WriteFileName << " is open ... " << endl;
			cout << "\t\tWrite to " << WriteFileName << endl;
			for(int i = 0; i < data.size(); i++){
				fout << data[i] << " ";
			}
			fout.close();
			cout << "\tFile " << WriteFileName << " was closed ... " << endl;

		}else
		cout << "\tError" << "\n\tfile " << WriteFileName << " not found" << endl;

}
