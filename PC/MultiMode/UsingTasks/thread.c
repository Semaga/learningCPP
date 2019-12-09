#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "integral.h"

static double a = 0;
static double b = 1;
static int n = 100000000;

static double total = 0;

static pthread_mutex_t total_mutex = PTHREAD_MUTEX_INITIALIZER;

static int p;

void * process_function (void *pa)
	{
		int my_rank = (int)pa;
		double len = (b-a)/p;
		int local_n = n/p;
		double local_a = a + my_rank* len;
		double local_b = local_a + len;
		double integral;

		integral = integate (local_a, local_b, local_n);

		pthread_mutex_lock (&total_mutex);
		total+= integral;
		pthread_mutex_unlock (&total_mutex);
		return 0;
	}