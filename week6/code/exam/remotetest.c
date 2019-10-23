#include "staticlib.h"
#include <stdio.h>
#define num 100
int main()
{
	int a[num];
	initarray(a,num);
	showarray(a,num);
	printf("max = %4d\n",max(a,num));
	printf("sum = %4d\n",sum(a,num));
	return 0;
}
