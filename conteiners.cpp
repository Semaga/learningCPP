#include <iostream>
#include <string>
#include <vector>
#include <algorithm>// библиотека алгоритмов

using namespace std;

// int main(){
// 	string s= "hrygkhj,b vnf";
// 	vector<int> nums= {7,5,4,34,54,756,7,56,756,1, 3, 5, 7, 9, 5};
// 	int quant= count(begin(nums),end(nums), 5);
// 	for(auto c: nums){
// 		if (c== 5){
// 			quant++;
// 		}
// 	}
// 	cout<< "There are "<< quant<<'\n';


// 	sort(begin(nums), end(nums));
// 	for(auto c:nums){
// 		cout<<c<<'\n';
// 	}

// 	int x;
// 	cout << "Введите число: ";
// 	cin >> x;
// 	cout<< '\n'<< "x= " << x<< '\n';
// 	}


void PrintVector(const vector<bool> &v);
int main(){

	// int n;
	// cin >> n;// количество элементов
	// vector <string> v(n);




/* в этом случае вектор динамичен*/
	// vector <string> v;

	// int i= 0;

	// while(i< n){
	// 	string s;
	// 	cin >> s;
	// 	v.push_back(s);
	// 	cout<< "Currenn size= "<< v.size()<< endl;
	// 	++i;
	// }

	// for(string & s: v){
	// 	cin >> s;
	// 	cout<< "Currenn size= "<< v.size()<< endl;

	// }
	// PrintVector(v);

	vector<int> days_in_month= {31,28,31,30,31};	

	if(true){ //if year is leap
		days_in_month[1]++;

	}
	// PrintVector(days_in_month);

	vector<bool> is_holiday(28, false);
	is_holiday[22]= true;
	PrintVector(is_holiday);

	// is_holiday.resize(31);
	is_holiday.assign(31, false);// переобозначили вектор
	is_holiday[8]= true;
	PrintVector(is_holiday);	 
	return 0;
}


void PrintVector(const vector<bool> &v){
	cout<< endl;
	int i= 0;
	for(auto s: v){
		cout << i <<":"<< s  << endl;
		++i;
	}
} 