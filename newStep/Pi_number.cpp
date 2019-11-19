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
		sum = sum + pow(-1, n)/pow(2, 10*n) * ( - pow(2,5)/(4*n+1) - 1/(4*n+3) + 
			pow(2,8)/(10*n+1) - pow(2,6)/(10*n+3) - pow(2,2)/(10*n+5) - pow(2,2)/(10*n+7) + 1/(10*n+9)
		 ) ;
	}
	PI = 1/pow(2,6)*sum;
	t = (clock() - t);

	cout << "\n\n\t" << "Using equation of Bellard Pi-number equal is " 
	 <<PI  << endl;
	cout << "\tSpended time is " << t << "\n\n" << endl;
}




int main()
{
	long double pi = 0;
	Bellard(1);


	return 0;
}