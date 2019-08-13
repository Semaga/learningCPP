#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int Min_from_vec(const vector <int>&vec){
	int min;

	min = vec[0];
	for(const auto &i: vec){
		if (min > i){
			min = i;
		}
	}
	return min;
}
int Max_from_vec(const vector <int>&vec){
	int max;

	max = vec[0];
	for(const auto &i: vec){
		if (max < i){
			max = i;
		}
	}
	return max;
}

void Read_From_File(const string &file_name, 
										int &min, int &max){
	ifstream input(file_name);
	string line;
	vector <int> vec;
	int check;
	if(input){
		while(getline(input, line,' ')){
			check = stoi(line);
			vec.push_back(check);
		}
	}
	else 
		cout<< "\tError" << endl;
	cout << "\tvec:";
	for(const auto &i: vec){
		cout<< i << endl;
	}

	min = Min_from_vec(vec);
	max = Max_from_vec(vec);

}

main(){
	string file_name = "data_task_4.txt";
	int min = 0, max = 0;
	Read_From_File(file_name, min, max);

	cout << "\tResult\n";
	
	cout << "max, max " << max << " " << min << endl;
	// cout << "min = " << min << endl;

	return 0;
}
