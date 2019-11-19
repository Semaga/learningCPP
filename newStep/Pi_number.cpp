// This programme for calculation of pi-number


/*
Реализация формулы Белларда:

PI = 1/(2^6) summ(from n = 0 to n = inf) ( (-1)^n )/( 2^10n ) *
		( (-2)^5/(4n+1) -1/(4n+3) + 2^8/(10n+1) -2^6/(10n+3) - 2^2/ (10n+5) - 2^2/(10n+7) + 1/(10n+9) )

*/

#include <time.h>
#include <iostream>
#include <cmath>

using namespace std;

void Bellard(int N)
{
	long double PI = 0, sum = 0;
	clock_t t = clock();

	for(int n = 0; n < N; n++)
	{
		sum = sum + pow(-1.0, n)/pow(2.0, 10*n) * ( - pow(2.0,5)/(4.0*n+1) - 1/(4.0*n+3) + 
			pow(2.0,8.0)/(10.0*n+1.0) - pow(2.0,6.0)/(10.0*n+3.0) - 
			pow(2.0,2.0)/(10.0*n+5.0) - pow(2.0,2.0)/(10.0*n+7.0) + 1.0/(10.0*n+9.0)
		 ) ;
	}
	PI = 1/pow(2,6)*sum;
	t = (clock() - t);

	cout << "\n\n\t" << "Using equation of Bellard Pi-number equal is " 
	 <<PI  << endl;
	cout << "\tN = " << N << endl;
	cout << "\tSpended time is " << t << "\n\n" << endl;
}




int main()
{
	for(int i = 0; i < 1000; i+= 10){
		Bellard(i);
	}

	return 0;
}