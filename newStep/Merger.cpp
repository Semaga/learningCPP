#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void PrintVec(vector <T> &v){
	cout << "\tPrintVec:"<< endl;
	cout << "\t";
	for(const auto &i:v){
		cout << fixed;
		cout.precision(7);
		cout << i << ' ';
	}
	cout << endl;
}

void Compare_Merge(vector <int>&V1,
	vector <int>&V2, 
	vector <int> &result){

	
}

int main()
{
	srand(time(NULL));

	int N;

	cout << "Input lenght mass :";
	cin >> N;
	vector <int> V1, V2, V3;

	for(int i = 0; i < N; i++){
		V1.push_back((rand()%N)+1);
		V2.push_back((rand()%N)+1);
	}	

	PrintVec(V1);
	PrintVec(V2);



	return 0;
}