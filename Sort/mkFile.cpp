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

template <typename T>
void WriteVectorToFile(const string &WriteFileName, vector <T> &v, char delimiter = ' ');

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
		// PrintVec(data);
		int t;
		cout << "\t\t";
		cout << "Which algorithm you want to use?" << endl;
		cout << "Standart from std::vector - (press 1) "; cin >> t;
		if (t == 1) 
			sort(data.begin(), data.end());
			cout << "Sorting is done " << endl;	
		// PrintVec(data);
	}else
		cout << "\tError" << "\n\tfile " << ReadFileName << " not found" << endl;

		if (fout){
			WriteVectorToFile(WriteFileName, data, ' ');
		}else
		cout << "\tError" << "\n\tfile " << WriteFileName << " not found" << endl;

}

template <typename T>
void WriteVectorToFile(const string &WriteFileName, vector <T> &v, 
											 char delimiter)
{
	cout << "\t\tFucktion @WriteVectorToFile@ is ON" << endl;
	cout << "\t\t************************************" << endl;
	ofstream fout(WriteFileName);
	if(fout)
	{
		cout << "\t\t\tFile "<< WriteFileName <<" was open" << endl;
		for (const auto &i:v)
		{
			fout << i << delimiter;
		}
		cout << "\t\t\tRecording completed" << endl;
		fout.close();
		cout << "\t\t\tFile was closed" << endl;
		cout << "\t\t************************************" << endl;

	}else
		cout << "Error, file "<< WriteFileName <<" not found ..." << endl;
}

