#include "uhead.h"
#define MAX 100


int main()
{
	int i;
    struct arg argument1,argument2;
	struct timeval start,end;
	unsigned long timer;
	int a[MAX],b[MAX];
	urand(a,MAX);
	for(i = 0;i < MAX;i++){
		b[i] = a[i];	
	}
	printf("\n-----before sort array A is-----\n");
    show(a,MAX);
    argument1 = operater(a,MAX);
    printf("sum is %d,average is %.2f\n",argument1.sum,argument1.ave);
	gettimeofday(&start,NULL);	
	Mysort(a,MAX);
	gettimeofday(&end,NULL);	
	timer = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	printf("\n------After call Mysort function array A is------\n");
	show(a,MAX);
	printf("Mysort use time %ld us\n",timer);

	printf("\n\n\n");

	printf("\n-----before sort array B is-----\n");
    show(b,MAX);
	argument2 = operater(a,MAX);
    printf("sum is %d,average is %.2f\n",argument2.sum,argument2.ave);
	gettimeofday(&start,NULL);
	Syssort(b,MAX);
	gettimeofday(&end,NULL);	
	timer = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	printf("\n------After call Syssort function array B is------\n");
	show(b,MAX);
	printf("Syssort use time %ld us\n",timer);
	return 0;
}

