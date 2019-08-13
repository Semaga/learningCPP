#include <iostream>
#include <set>

using namespace std;

int main(int argc, char  **argv){
	/* code */
	set <int> s;

	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);

	for (auto i = s.rbegin(); i!= s.rend(); ++i){
		cout << *i <<  ' '; 
		/* code */
	}
	cout << endl;

	return 0;
}