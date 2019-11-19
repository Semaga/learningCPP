// This programme for calculation of pi-number


/*
Реализация формулы Белларда:

PI = 1/(2^6) summ(from n = 0 to n = inf) ( (-1)^n )/( 2^10n ) *
		( (-2)^5/(4n+1) -1/(4n+3) + 2^8/(10n+1) -2^6/(10n+3) - 2^2/ (10n+5) - 2^2/(10n+7) + 1/(10n+9) )

*/

#include <time.h>
#include <iostream>
#include <cmath>


void Bellard(int N)
{
	long double PI = 0;
	clock_t t = clock();

	for(int n = 0; n < N; n++)
	{
		PI = 0;
	}


}

using namespace std;

int main()
{
	long double pi = 0;




	return 0;
}