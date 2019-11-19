// This programme for calculation of pi-number


/*
Реализация формулы Белларда:

PI = 1/(2^6) summ(from n = 0 to n = inf) ( (-1)^n )/( 2^10n ) *
		( (-2)^5/(4n+1) -1/(4n+3) + 2^8/(10n+1) -2^6/(10n+3) - 2^2/ (10n+5) - 2^2/(10n+7) + 1/(10n+9) )

*/

#include <time.h>
#include <iostream>
#include <cmath>

#include <cstdlib>
#include <iomanip>

using namespace std;

void Bellard(int N, bool only_answer = false)
{
	long double PI = 0.0, sum = 0.0;
	
	srand(time(0));
	for(int n = 0; n < N; n++)
	{
		sum = sum + pow(-1.0, n)/pow(2.0, 10*n) * ( - pow(2.0,5)/(4.0*n+1) - 1/(4.0*n+3) + 
			pow(2.0,8.0)/(10.0*n+1.0) - pow(2.0,6.0)/(10.0*n+3.0) - 
			pow(2.0,2.0)/(10.0*n+5.0) - pow(2.0,2.0)/(10.0*n+7.0) + 1.0/(10.0*n+9.0)
		 ) ;
		// if (n%10 == 0)
		// 	cout << "\t" << n << " itteration complited\n"<< endl;  
	}
	PI = 1/pow(2.0, 6.0)*sum;
	if(only_answer)
	{
		cout.precision(N);
		cout << "\n\n\t" << "Using equation of Bellard Pi-number equal is " << PI << endl;
		cout << "\t N = " << N << endl;
		cout.precision(5);
		cout << "\tSpended time is " << clock()/1000.0 << "\n\n" << endl;
	}
	else
	{
		cout << "\n\n\t" << "Bellard " << "\n\t\t" <<
				" Pi-number = " << PI << "\t t = " << clock()/1000.0 << endl;
	}

}

// Формула Бэйли — Боруэйна — Плаффа:
void BBP(int N, bool only_answer = false)
{
	long double PI = 0.0;
	srand(time(0));
	for(int i = 0; i < N; i++){
		PI = PI + 1/pow(16.0, i) * ( 4.0/(8.0*i + 1) - 2.0/(8.0*i + 4.0) 
			- 1.0/(8.0*i + 5.0) - 1.0/(8.0*i +6.0) );
		// if (i%10 == 0)
		// 	cout << "\t" << i << " itteration complited\n"<< endl;  

	}
	if(only_answer)
	{
		cout.precision(N);		
		cout << "\n\n\t" << "Using equation of Baly-Boruwaune-Plaffe Pi-number equal is " << PI << endl;
		cout << "\t N = " << N << endl;
		cout.precision(5);
		cout << "\tSpended time is " << clock()/1000.0 << "\n\n" << endl;
	}
	else
		cout << "\n\n\t" << "Baly-Boruwaune-Plaffe " << "\n\t\t" <<
						" Pi-number = " << PI << "\t t = " << clock()/1000.0 << endl;

}



int main()
{
	for(int i = 1; i < 10001; i=i*10)
		{
			Bellard(i, true);
			BBP(i, true);
		}
	
	return 0;
}