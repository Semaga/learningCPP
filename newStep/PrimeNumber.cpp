#include <iostream>
#include <vector>

using namespace std;

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

void PrimeNumber(int number)
{
	vector<int> v;
	int curNumber = number;
	int probe = 2;

	while(curNumber != 1){
		if(curNumber%probe != 0){
			probe++;
		}
		else
		{
			curNumber/=probe;
			v.push_back(probe);
		}
	}
	vector <int> a;
	a.push_back(v[0]);
	for(size_t i = 1; i < v.size(); i++){
		for(size_t j = 0; j < v.size(); j++ ){
			if(v[j]!=v[i])
				a.push_back(v[j]);
		}
	}

	PrintVec(a);
	PrintVec(v);

}


int main()
{
	int t;
	cout << "Input number : " ;
	cin >> t;
	PrimeNumber(t);
	return 0;
}
