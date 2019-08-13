#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <random>
#include <vector>
#include <utility>

using namespace std;

void Multiply(const vector <vector <int>> v1, const vector <vector <int>> v2, 
	vector <vector <int>> v_result){
	v_result.resize(v1.size());
	for(auto &i:v_result){
		for(auto &j:v2){
			i.resize(j.size());
		}
	}
	for(auto &i:v_result){
		for(auto &j:i){
			j=0;
		}
	}

	for(int i= 0; i!= v1.size(); ++i){
		for(int j= 0; j!= v2.size();++j){
			for(int k= 0; k!= v1[0].size(); ++k){
				v_result[i][j]+= v1[i][k]*v2[k][j]; 
			}
		}
	}

	for(const auto &i:v_result){
		for(const auto &j:i){
			cout<< j << ' ';
		}
		cout<< endl;
	}

}

void FromStringToVector(const string& str, vector<int>&v){
	bool in_num= false;
	string check;
	for(int i= 0; str[i]!= '\0';++i){
		if(str[i]!= ' '){
			in_num= true;
			check+= str[i];
		}else if(str[i]== ' '){
			in_num= false;
			v.push_back(atoi(check.c_str()));
			check.clear(); 
		}

	}
}

int main(){
	srand(0);
	int rows= 4, colums= 5;
	vector <vector <int>> v;

	v.resize(rows);
	for(auto &i:v){
		i.resize(colums);
	}

	ofstream fout1("1CPP.txt");//для записи
	for(auto &i:v){
		for(auto &j:i){
			j= rand()%10;
			fout1 << j << ' ';
		}
		fout1 << endl;
	}
	v.clear();
	fout1.close();

	v.resize(colums);
	for(auto &i:v){
		i.resize(rows);
	}


	ofstream fout2("2CPP.txt");//для записи
	for(auto &i:v){
		for(auto &j:i){
			j= rand()%10;
			fout2 << j << ' ';
		}
		fout2 << endl;
	}
	fout2.close();
	v.clear();

	vector <vector <int>> v1;
	vector <vector <int>> v2;
	vector <vector <int>> v3;

	ifstream fin1("1CPP.txt");
	if(fin1){
		string line;
		while(getline(fin1,line)){
			vector<int> check;
			cout<< line << endl;
			FromStringToVector(line, check);
			v1.push_back(check);
			check.clear();
		}
		cout<< "\tDone"<< endl;
	}else {
		cout<< "\tErrors!"<< endl;
	}
	fin1.close();

	ifstream fin2("2CPP.txt");
	if(fin2){
		string line;
		while(getline(fin2,line)){
			vector<int> check;
			cout<< line << endl;
			FromStringToVector(line, check);
			v2.push_back(check);
			check.clear();
		}
		cout<< "\tDone"<< endl;
	}else {
		cout<< "\tErrors!"<< endl;
	}
	fin2.close();


	cout<< "Вектор v1" << endl;	
	for(const auto& i:v1){
		for(const auto& j:i){
			cout<< j<< ' ';
		}
		cout<< endl;
	}
	cout<< endl;

	cout<< "Вектор v2" << endl;	
	for(const auto& i:v2){
		for(const auto& j:i){
			cout<< j<< ' ';
		}
		cout<< endl;
	}
	
	cout<< "Умножение\n";
	for(const auto &i:v3){
		cout << "123";
		for(const auto &j:i){
			cout<< j<< ' ';
		}
		cout<< endl;
	}
	Multiply(v1,v2,v3);
	cout<< "Умножение- результат\n";

	return 0;
}


