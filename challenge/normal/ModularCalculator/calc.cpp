#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


vector <string> split(string & s, char delimeter = ' '){
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delimeter)){
		tokens.push_back(item);
	}
	return tokens;
}

int Solved(string &Operation, string &secondNumber, int firstNumber){
	int solv = 0, sec = 0;
	sec = stoi(secondNumber);
	if (Operation == "+"){
		solv = firstNumber  +  sec;
	}else if(Operation == "-"){
		solv = firstNumber  - sec;
	}else if(Operation == "*"){
		solv = firstNumber  * sec;
	}else if(Operation == "/"){
		solv = firstNumber / sec;
	}else if(Operation == "%"){
		solv = firstNumber  % sec;
	}
	cout << "Operation" << endl;
	cout << "\t" << Operation << ' ' << secondNumber << endl;
	return  solv;
}


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


int main(){

	ifstream fin1("5.txt");
	if(fin1){
		vector <string> secondLine;
		string line;
		int Number;
		string Operation;
		getline(fin1,line); //read the first line - number of lines 
		Number = stoull(line);
		while(getline(fin1, line)){
			secondLine = split(line);
			cout << Number << endl;
			Number = Solved(secondLine[0],secondLine[1], Number);
			cout << Number << endl;
		}
		cout << "Result = " << Number << endl;
		cout<< "\tDone"<< endl;
	}else {
		cout<< "\tErrors!"<< endl;
	}
	fin1.close();

	return 0;
}

