#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <sys/types.h>
struct sendval 
{
	int n,s;
};

#define LOOP 100000000
#define NUM 4

