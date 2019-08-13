#include <iostream>

using namespace std;

int main(){

	int n,t= 10000;

	cout<< "\tДеление числа на разряды" << endl<< endl;
	cout<< "Введите пятизначное число: ";
	cin>> n;
	cout<< endl << n << endl<< endl;

	int i= 0;
	
	while(i< 5){
		cout<< i+1 << " число равно " << (n- n%t)/t<< endl; 
		n=n%t; 
		t=t/10;
		++i;
	}


	return 0;
}