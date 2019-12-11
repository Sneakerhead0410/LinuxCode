#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#define NUM 4

struct Cal{
	int i;
	int max;
};
