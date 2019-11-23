#include <iostream>

using namespace std;

int Kollatsa(int &n);

int main()
{
	int Number;

	cout << "Input int number :" << endl;
	cin >> Number;

	cout<< "Number of steps - " <<Kollatsa(Number) << endl;

	return 0;
}


int Kollatsa(int &n){
	int Step=0;

	while(n!=1){
		if(n%2 == 0)
		{
			n/=2;
		}else{
			n = n*3+1;
		}
		Step++;
	}

	return Step;
}