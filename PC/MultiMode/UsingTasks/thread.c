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