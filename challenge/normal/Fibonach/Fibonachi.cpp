/*
Проблема с большими числаси 

"""
libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: stoull: out of range
Abort trap: 6
"""

можно решить без больших числе, но не понятно как????
*/


#include <iostream>
#include <fstream>

using namespace std;

void Fibonachi(int N){
	int a = 0, b = 1, c = 0;
	cout << "Fibonachi seq is:" << endl;
	for(int i = 0; i < N; i++){
		cout << a << endl;
		c = a;
		a += b;
		b = c;
	}
}

void FindInSeq(long long int &it){
	long long int a = 0, b = 1, c = 0;
	long int i = 0;

	while( a!= it){
		c = a;
		a += b;
		b = c;
		// cout << "Itter " << i << " done" << endl;
		++i;
	}
	// cout << "Number of itteration equal is " << i << endl;
	cout << i << ' ';
}

int main(){

	// int N;
	// long long int a = 0, b = 1, c = 0;

	// long long int i = 0, it = 0;
	// cout << "Inpute number "; cin >> it;

	ifstream fin1("5.txt");
	if(fin1){
		string line;
		int NumberOfLines;
		unsigned long long int Number;
		getline(fin1,line); //read the first line - number of lines 
		NumberOfLines = stoi(line);
		for(int i = 0; i < NumberOfLines; ++i){
			getline(fin1, line);
			Number = stoull(line);
			// FindInSeq(Number);
		}

		cout<< "\tDone"<< endl;
	}else {
		cout<< "\tErrors!"<< endl;
	}
	fin1.close();

	// FindInSeq(it);

	return 0;
}
