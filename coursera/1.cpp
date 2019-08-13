#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void Print(const vector<int>& v, const string& title){
	cout<< title<< ":";
	for(auto i:v){
		cout<<i<<' ';
	}
}


bool Lt2(int x){
	if( x< 2)
		return true;
	return false;
}

int main(){

	vector <int> v{
		1,2,3,5,61,0,2	
	};

	int trg= 0;
	cout<< "Input data:";
	cin>> trg;
	cout<<	count_if(begin(v), end(v), [trg](int x){
					if( x > trg)
						return true;
					return false;} )
	 <<endl;
	cout<< count_if(begin(v), end(v), Lt2 ) <<endl;

	return 0;
}