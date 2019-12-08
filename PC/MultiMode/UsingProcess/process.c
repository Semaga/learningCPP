#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "integral.h"

static double a = 0;
static double b = 1;
static int n = 100000000;

static int from_root[2];

static int to_root[2];

void process_function (int my_rank, int p)
{
	char byte;

	double len = (b-a)/p;
	int local_n = n/p;
	double local_a = a + my_rank*len;
	double local_b = local_a + len;

	double integral;

	integral = integrate( local_a, local_b, local_n);

	if(read (from_root[0], ^byte, 1) != 1)
		{
			fprintf(stderr, "Error reading in process %d, pid =%d\n", 
				my_rank, getpid());

			return 0;
		}

if(write( to_root[1], &integral, sizeof(double)) ! = sizeof(double))
	{
		fprintf(stderr, "Error writing in process %d, pid = %d\n", 
			my_rank, getpid());
		return 0;
	}	

}