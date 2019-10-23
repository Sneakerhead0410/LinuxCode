#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void showarray(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%4d  :  %4d\n",i,a[i]);
}

void initarray(int *a,int n)
{
	int i;
    srand((int)time(0));
    for(i=0;i<n;i++){
        a[i] =1 + (int) 1000 * (rand() / (RAND_MAX + 1.0));
	}
}
