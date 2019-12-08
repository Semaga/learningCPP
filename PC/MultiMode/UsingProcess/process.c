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

	if(read (from_root[0], &byte, 1) != 1)
		{
			fprintf(stderr, "Error reading in process %d, pid =%d\n", 
				my_rank, getpid());
		return;
		}

	if(write( to_root[1], &integral,  sizeof(double)) ! = sizeof(double))
		{
			fprintf(stderr, "Error writing in process %d, pid = %d\n", 
				my_rank, getpid());
			return;
		}	

}

int main(int argc, char  *argv[])
	{
		/* Идентифакатора запуска процесса*/
		pid_t pid;
		/* General number of process */
		int p;
		int i;
		char byte;
		double integral = 0.;
		double total = 0.;

		if(argc != 2)
			{
				printf("Usage: %s <instance> \n", argv[0]);
				return 1;
			}	
		/*Get number of process*/
		p = (int) strtol (argv[1], 0, 10);
		
		/*Make the channel*/	
		if (pipe (from_root) == -1 || pipe (to_root)==-1)
			{
				fprintf(stderr, "Cannot pipe!\n");
				return 2;
			}
		/*Get started process*/

		for (i = 0; i < p; i++)
			{
				/*Clone myself*/
				pid = fork ();
				if (pid == -1)
					{
						fprintf(stderr, "Cannot fork!\n");
						return 3+i;
					}
				else if (pid ==0)
					{
						/*Process is descendant*/
						/*Close unnecessart dircet of exchenge*/
						close (from_root[1]);
						close(to_root[0]);

						/*Do calculation*/
						process_function (i,p);

						/*Close channel*/
						close (from_root[0]);
						close (to_root[1]);

						return 0;
					}
			}	

			close (from_root[0]);
			close (to_root[1]);

			/*Get result*/
			for(i = 0; i<p; i++)
				{
					byte = (char)i;
					if (write (from_root[1], &byte,1)!=1)
						{
							/*Write failed*/
							fprintf(stderr, "Error writing in root process\n");
							return 100;
						}
					/*Read result*/
					if (read (to_root[0], &integral, sizeof (double))!= sizeof(double))
						{
							fprintf(stderr, "Error reading in root process\n");
							return 101;
						}	

					total += integral;	

				}
			/*Close a channel*/
			close (from_root[1]);
			close (to_root[0]);

			printf("Integral from %lf to %lf = %.18lf\n", a,b,total);	

		return 0;
	}
