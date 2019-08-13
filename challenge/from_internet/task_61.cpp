#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;

typedef unsigned long int Lint;

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

void Work(const vector <int> &v){

}

void Test(){
	int N = 200000;
	vector <Lint> v;
	for(int i = 0; i < N+1; i++){
		v.push_back(i);
	}
	v[1] = 0;
	vector <Lint> First;
	int j = 2;
	while(j <= N){
		if (v[j] != 0){
			First.push_back(v[j]);
			for(int k = j; k < N+1; k+=j){
				v[j] = 0;
			}
		}
	}
	PrintVec(First);
}

main(){
	string file_name = "data_task_4.txt";
	string line;
	vector <string> v;
	vector <int> vec;
	int N;
	ifstream input(file_name);
	getline(input, line);
	// N = stoi(line);
	// cout << "N = " << N << endl;
	// for (int i = 0; i < N; i++){
	// 	getline(input, line);
	// 	v = split(line);
	// 	vec = FromStrToInt(v);
	// 	Work(vec);
	// }
	Test();
	return 0;
}
	