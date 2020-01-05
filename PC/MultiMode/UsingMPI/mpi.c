#include <stdio.h>
#include "mpi.h"
#include "integral.h"

static double a = 0;
static double b = 1;
static int n = 100000000;

static double total = 0;

void process_function(int my_rank, int p)
	{	
		double len = (b-a)/p;

		int local_n = n/p;
		double local_a = a + my_rank*len;
		double local_b = local_a + len;
		double integral;

		integral = integrate( local_a, local_b, local_n);

		MPI_Reduce (&integral, &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	}

int main(int argc, char const **argv)	
	{
		int my_rank;
		int p;

		MPI_Init (&argc, &argv);

		MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);
		MPI_Comm_size (MPI_COMM_WORLD, &p);

		process_function (my_rank, p);

		if (my_rank ==0 )
			{
				printf("Integral from %lf to %lf =%.18lf\n", a, b, total);
			}

		MPI_Finalize();

		return 0;
	}