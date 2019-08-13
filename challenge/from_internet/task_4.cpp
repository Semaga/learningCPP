#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void Read_From_File(const string &file_name, 
										vector <int> &vec){
	ifstream input(file_name);
	int data_len = 0, data_a = 0, data_b = 0;
	string check;
	string a, b, line;
	if(input){
		getline(input, check);
		data_len = stoi(check);
		vec.resize(data_len);
		cout<< "check = " << check << endl;
		cout<< "data_len = " << data_len << endl;
		for(int i = 0; i< data_len; ++i){
			getline(input, a, ' ');
			stringstream convert(a);
			getline(input, b);
			convert >>  data_a;
			// stringstream convert(b);
			// convert >>  data_b;
			// data_a = stoi(a);
			data_b = stoi(b);
			// getline(input, b, ' ');
			cout << "\ti =    " << i      << endl;
			cout << "str_a =  " << a      << endl;
			cout << "data_a = " << data_a << endl; 
			cout << "str_b =  " << b      << endl;
			cout << "data_b = " << data_b << endl; 
			vec[i]= min(data_a,data_b);
		}
	}
	else 
		cout<< "\tError" << endl;
}

main(){
	vector <int> c;
	vector <vector <int>> data_vec;
	string file_name = "data_task_4.txt";
	Read_From_File(file_name, c);

	string chr = "-7485747 2868797";
		

	int qwe = stoi(chr);

	cout << "\tResult\n";
	for(const auto &i:c){
		cout<< i << endl;
	}


	return 0;
}