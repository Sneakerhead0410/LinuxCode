#include "uhead.h"
struct arg operater(int *a,int max){
	int i;
    struct arg argument;
	for(i = 0;i < max;i++){
		argument.sum += a[i];
    }
    argument.ave = argument.sum / (float)max;
    return argument;
}
