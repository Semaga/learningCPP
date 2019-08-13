#include <iostream>

using namespace std;
int main(){

	int a, b, f, x;

	cout << "Введите a = "; cin >> a; cout << endl;
	cout << "Введите b = "; cin >> b; cout << endl;
	cout << "Введите f = "; cin >> f; cout << endl;

	cout << "a = " << a << " "<< "b = " << b << " " << "f = " << f << endl;
	x= a+b -f/a + f*a*a-(a+b);
	// x = (а + b - f/а) + f * a * a - (a + b);
	cout << "Вычислим по формуле 	x= (а + b — f / а) + f * a * a — (a + b);"<< endl;
	cout << "x = "<< x << endl;
	return 0;
}