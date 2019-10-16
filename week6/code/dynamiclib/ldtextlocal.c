#include <stdio.h>
#include "dylib.h"
#define num 100
int main()
{
	int a[num];
	init(a,num);
	show(a,num);
	printf("max = %4d\n",max(a,num));
	printf("sum = %4d\n",sum(a,num));
}
