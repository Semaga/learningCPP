#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;

template <typename T>
void PrintVec(vector <T> &v){
	cout << "PrintVec:"<< endl;
	cout << "\t";
	for(const auto &i:v){
		cout << fixed;
		cout.precision(7);
		cout << i << ' ';
	}
	cout << endl;
}

vector <string> split(string & s, char delimeter = ' '){
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delimeter)){
		tokens.push_back(item);
	}
	return tokens;
}

void Aver( vector<double> &v){
	cout << "Before ave" << endl;
	PrintVec(v);
	vector <double> a = v;
	for (int i = 1; i != v.size() - 1; ++i){
		a[i] = (v[i-1] + v[i+1] + v[i])/3;
	}
	cout << "After ave" << endl;
	PrintVec(a);
}

main(){
	string file_name = "data_task_4.txt";
	string line;
	vector <string> v;
	vector <double> vec;
	int N;
	ifstream input(file_name);
	getline(input, line);
	N = stoi(line);
	cout << "N = " << N << endl;
	getline(input, line);
	v = split(line);
	for (const auto &i:v){
		vec.push_back(stof(i));
	}
	Aver(vec);
	return 0;
}
