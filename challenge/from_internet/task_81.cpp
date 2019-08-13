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

long dvoich(int x1)     
 {   
     int i, b;   
     long c = 0;   
     for(i=0;x1 > 0;i++)   
     {          
        b = x1 % 2;   
         x1 = (x1-b)/2; 
         c += b * pow(10,i); 
     }  
   
     return c;     
 }

void Func(int n) {

 if (n != 0)
 Func(n / 2);
 else return;

 printf("%d", n % 2);
 return;
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
	getline(input, line);
	v = split(line);
	vec = FromStrToInt(v);
	for( const auto &i: vec){
		cout << i << endl;
		cout << "dvoich:" << dvoich(i) << endl;
		cout << endl;
		Func(i);
		cout << endl;
	}
	return 0;
}
	