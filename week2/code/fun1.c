#include "uhead.h"

void show(int *a,int max)
{
	int i;
    for(int i = 0;i < max;i++){
        printf("a[%d] = %d \n",i,a[i]);
	}
}

void urand(int *a,int max)
{
    int i;
    srand((int)time(0));
    for(i=0;i<max;i++){
        a[i] =1 + (int) 1000 * (rand() / (RAND_MAX + 1.0));
	}
}
