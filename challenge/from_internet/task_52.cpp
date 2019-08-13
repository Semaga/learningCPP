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

vector <int> FromStrToInt(const  vector <string> &v){
	// cout << "Come in FromStrToInt" << endl;	
	vector <int> s;
	for(const auto &i:v){
		s.push_back(stoi(i));
	}
	return s;
}

void MaxMinMidInVec(vector <int> &v){
	// cout << "Come in MaxMinMidInVec" << endl;
	int b = 0;
	vector <int> a;
	for(const auto &i: v){
		if(b < i){
			b = i;
		}
	}
	a.push_back(b);
	for(const auto &i: v){
		if(i < b){
			b = i;
		}
	}
	a.push_back(b);
	for(const auto &i: v){
		if((i < a[0]) && (i > a[1])) {
			a.push_back(i);
		}
	}
	// PrintVec(a);
	v = a;
}

void Work(vector <int> &v){
	// cout << "Come in Work" << endl;
	MaxMinMidInVec(v);
	if(v[0]*v[0] ==  v[1]*v[1] + v[2]*v[2]){
		cout << "R" << endl;	
	}else if(v[0]*v[0] > v[1]*v[1] + v[2]*v[2]){
		cout << "O" << endl;
	}else if(v[0]*v[0] < v[1]*v[1] + v[2]*v[2]){
		cout << "A" << endl;
	}
	// PrintVec(v);
}

main(){
	string file_name = "data_task_4.txt";
	string line;
	vector <string> v;
	vector <int> vec;
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
