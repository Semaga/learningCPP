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

