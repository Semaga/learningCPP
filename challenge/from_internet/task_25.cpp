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

vector <int> FromStrToInt(const vector <string>&v){
	vector <int> a;
	for(const auto &i:v){
		a.push_back(stoi(i));
	}
	return a;
}

void Work(const vector<int> &v){
	int A, C, M, X0, N, Xc;
	A = v[0]; 
	C = v[1];
	M = v[2];
	X0 = v[3];
	N = v[4];
	for (int i = 0; i < N; ++i){
		Xc = (A * X0 + C) % M;
		X0 = Xc;
	}
	cout << Xc << endl;
}

main(){
	string file_name = "data_task_4.txt";
	
	ifstream input(file_name);
	string line;
	if(input){
		while(getline(input, line)){
			cout << line << endl;
		}
		cout << "Done" << endl;
	}else{
		cout << "Error" << endl;
	}

	return 0;
}
