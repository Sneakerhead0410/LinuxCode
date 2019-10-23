#include "uhead.h"

int comp(const void *p1,const void *p2)
{
        return  *((int*)p2)>*((int*)p1)?-1:1;
}

void Syssort(int *a,int num)
{
	 qsort(a, num,sizeof(int),comp);
}
