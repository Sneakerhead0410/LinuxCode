#include "my.h"

void * threadfun(void *arg)
{
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	pid_t pid;
	int i,ret;
	struct timeval tv1,tv2;
	struct timezone tz;
	gettimeofday(&tv1,&tz);
	for(i = 0;i < 10000;i++)
		fork();
	gettimeofday(&tv2,&tz);
	printf("runing time is %ld\n",tv2.tv_usec - tv1.tv_usec);
	return 0;
}
