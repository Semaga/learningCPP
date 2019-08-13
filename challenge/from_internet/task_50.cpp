#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Work{
	private:
		
	public:
		string s, newStr, midleStr;

		void toOneRegistr(string &s){
			for (int i = 0; s[i] != '\0'; i++){
				s[i] = (char)tolower(s[i]);
				if (s[i]>= 'A' && s[i]<= 'Z'){
					newStr+= (char)tolower(s[i]);
				}else if(s[i]>= 'a' && s[i]<= 'z'){
					newStr+= s[i];					
				} 
			}		
		}
		void Compare(){
			midleStr = newStr;
			// cout << "midleStr = " << midleStr;
			reverse(midleStr.begin(), midleStr.end());
			if(midleStr == newStr ){
				cout << "Y" << endl;
			}else{
				cout << "N"<< endl;
			}
			midleStr.clear();
			newStr.clear();
		}

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
	Work task;
	ifstream input(file_name);
	vector <int> data;
	vector <string> vect;
	string line;
	unsigned long int TheFirst; 
	int kol = 0;
	if(input){
		getline(input, line);
		kol = stoi(line);
		while(kol > 0){
			getline(input, line);
			task.toOneRegistr(line);
			task.Compare();
			kol--;
			// cout << "Iterattion ok" << endl;
		}
	}
	else 
		cout<< "\tError\n\t\tEndOfFile" << endl;
}

main(){

	string file_name = "data_task_4.txt";
	Read_From_File(file_name);
	

	return 0;
}
