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

	PrintVec(v);

}


int main()
{
	PrimeNumber(15);
	return 0;
}
