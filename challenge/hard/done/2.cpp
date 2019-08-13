#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;
void PrintVec(const vector<int>&v){
	cout<< "PrintVec"<< endl <<  "\t(";
	for(const auto &i:v){
		cout<< i << ' ';
	}
	cout<< ")"<< endl;
}

void zapoln(vector<int>&v){
	for(auto &i:v){
		i= rand()%100;
	}
}

template<typename T>
void selection_sort(vector<T> &v) {
	for (int idx_i = 0; idx_i < v.size() - 1; idx_i++) {
		int min_idx = idx_i;
		for (int idx_j = idx_i + 1; idx_j < v.size(); idx_j++) {
			if (v[idx_j] < v[min_idx]) {
				min_idx = idx_j;
			}
		}

		if (min_idx != idx_i) {
			swap(v[idx_i], v[min_idx]);
		}
  }
}

template <typename T>
void Sheker_Sort(vector <T> &v){
	int right = v.size()- 1, left = 0;
	bool flag= true;

	while( (left < right) &&  flag== true){
		flag = false;
		for(int i= left; i < right; i++){
			if(v[i]>v[i+1]){
				swap(v[i],v[i+1]);
				flag = true;
			}
		}
		right --;
		for(int i= right; i > left; i--){
			if(v[i-1]>v[i]){
				swap(v[i-1],v[i]);
				flag = true;
			}
		}		
		left++;

	}

}

int main(){
	srand(0);

	vector <int> vec1,vec2;
	vec1.resize(10);
	vec2.resize(10);

	zapoln(vec1);
	vec2= vec1;

	PrintVec(vec1);

	selection_sort(vec1);
	cout<< "result selection_sort " << endl;
	PrintVec(vec1);
	cout << "result Sheker_Sort " << endl;
	PrintVec(vec2);

	Sheker_Sort(vec2);
	PrintVec(vec2);

	return 0;
}


