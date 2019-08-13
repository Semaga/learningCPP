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

vector <float> FromStrToInt(const  vector <string> &v){
	// cout << "Come in FromStrToInt" << endl;	
	vector <float> s;
	for(const auto &i:v){
		s.push_back(stof(i));
	}
	return s;
}

void Work(const vector <float> &v){
	float time = v[0]/(v[1]+v[2]);
	float s = time*v[1];
	cout << fixed;
	cout.precision(7);
	cout << s << endl; 
}

main(){
	string file_name = "data_task_4.txt";
	string line;
	vector <string> v;
	vector <float> vec;
	int N;
	ifstream input(file_name);
	getline(input, line);
	N = stoi(line);
	cout << "N = " << N << endl;
	for (int i = 0; i < N; i++){
		getline(input, line);
		v = split(line);
		vec = FromStrToInt(v);
		Work(vec);
	}
	return 0;
}
