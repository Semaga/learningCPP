#include <stdio.h>
#include "integral.h"

static double a = 0;
static double b = 1;
static int n = 100000000;

int main()
{
	double total = 0;

	total = integrate (a,b,n);
	printf("Integral from %1f to %1f = %.191f\n", a, b, total);

	return 0;
}