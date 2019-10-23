#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct arg{
	float ave;
    int sum;
};

void show(int *,int);
void urand(int *,int);
struct arg operater(int *,int);
void Mysort(int *,int);
void Syssort(int *,int);
