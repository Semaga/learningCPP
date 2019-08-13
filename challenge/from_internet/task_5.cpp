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
	int data_len = 0, data_a = 0, data_b = 0, data_c = 0, sr1 = 0, sr2 = 0;
	string check;
	string a, b, c, line;
	if(input){
		getline(input, check);
		data_len = stoi(check);
		// vec.resize(data_len);
		cout<< "check = " << check << endl;
		cout<< "data_len = " << data_len << endl;
		for(int i = 0; i< data_len; ++i){
			getline(input, a, ' ');
			getline(input, b, ' ');
			getline(input, c);

			// stringstream convert(a);
			// convert >>  data_a;
			data_a = stoi(a);
			data_b = stoi(b);
			data_c = stoi(c);
			// stringstream convert(b);
			// convert >>  data_b;
			// data_a = stoi(a);
			// getline(input, b, ' ');
			cout << "\ti = " << i      << endl;
			// cout << "str_a =  " << a      << endl;
			cout << "\t\tdata_a = " << data_a << endl; 
			// cout << "str_b =  " << b      << endl;
			cout << "\t\tdata_b = " << data_b << endl; 
			// cout << "str_c =  " << c      << endl;
			cout << "\t\tdata_c = " << data_c << endl; 


			sr1 = min(data_a, data_b);
			sr2 = min(data_b, data_c);
			cout << "sr1 = " << sr1 << endl;
			cout << "sr2 = " << sr2 << endl;
			cout << "Min = " << min(sr1, sr2) << endl;  
			// sr2 = min(data_b, data_c);
			// cout<< "sr2 = " << sr2 << endl;
			vec.push_back(min(sr1, data_c));
			// sr1 = 0; sr2 = 0;
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