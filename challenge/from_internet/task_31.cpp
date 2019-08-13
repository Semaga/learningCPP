#include <iostream>
#include <stdlib.h>
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
////////////////
void Rotate(int &k, string &line){
	// cout << "Come in Rotate" << endl;
	string b,c;
	if(k > 0){
		b = line.substr(0, k);
		for(int i = k; i < line.size(); i++){
			c+= line[i];
		}
		c+=b;
		// cout << "Results = " << c << endl;
		cout  << c << endl;

	}else{
		b = line.substr(line.size()+k,line.size());
		for(int i = 0; i<line.size()+k; ++i){
			c += line[i];
		}
		b+=c;
		// cout << "Results = " << b << endl;
		cout << b << endl;

	}
}


main(){
	string file_name = "data_task_4.txt";
	string line;
	vector <string> vec;
	int N;
	int k;
	ifstream input(file_name);
	getline(input, line);
	N = stoi(line);
	cout << "N = " << N << endl;
	for(int i = 0; i < N; ++i){
		getline(input, line);
		vec = split(line);
		// PrintVec(vec);
		k = stoi(vec[0]);
		Rotate(k, vec[1]);
	}
	/* code */
	return 0;
}
