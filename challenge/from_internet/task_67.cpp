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

void Work(const unsigned long long int &num){
	unsigned long long int a[3];
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	int k;
	for(k = 1; a[2]!=num ;k++){
		a[2] = a[0] + a[1];
		a[0] = a[1];
		a[1] = a[2];
	}
	cout << "Results" << endl;
	cout << k << endl;
}

main(){
	string file_name = "data_task_4.txt";
	string line;
	int N;
	unsigned long long int k;
	ifstream input(file_name);
	// getline(input, line);
	// N = stoi(line);
	cout << "Input N: "; cin >> N;
	for(int i = 0; i < N; ++i){
		// getline(input, line);
		cout << "Input num: ";
		cin >> k;
		// k = strtoull(line);
		Work(k);
	}
	/* code */
	return 0;
}
