#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Task{
	private:
		
	public:
		Task();
		~Task();
	
};

////////////////
//Split function
////////////////
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


////////////////
//Print vector function
////////////////
template <typename T>
void PrintVec(vector <T> &v){
	cout << "PrintVec:"<< endl;
	cout << "\t";
	for(const auto &i:v){
		cout << i << ' ';
	}
	cout << endl;
}
////////////////



void Read_From_File(const string &file_name){
	ifstream input(file_name);
	vector <int> data;
	vector <string> vect;
	string line;
	unsigned long int TheFirst; 
	int kol = 0;
	if(input){
		while(getline(input, line)){
			cout << line << endl;
			if(kol == 0){
				TheFirst = stoi(line);
			}else{
				vect = split(line);
				if (vect.size() > 2){
					cout<< "Error - " << endl;
				}
				if(vect[0] == "+"){
					TheFirst += stoi(vect[1]);
				}else if(vect[0] == "*"){
					TheFirst *= stoi(vect[1]);					
				}else if(vect[0] == "%"){
					TheFirst = TheFirst % stoi(vect[1]);
				}

			}
			kol++;
			cout << "TheFirst = " << TheFirst << endl;
		}
		cout << "Answer = " << TheFirst << endl;
		cout << endl;
	}
	else 
		cout<< "\tError\n\t\tEndOfFile" << endl;
}

main(){
	string file_name = "data_task_4.txt";
	Read_From_File(file_name);
	return 0;
}
