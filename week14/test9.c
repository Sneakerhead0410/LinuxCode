#include "my.h"
#include<pthread.h>

int arg = 0;
void * foo(void *v)
{
	printf("thread is running!\n");
	return (void *)0;
}
int main()
{
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid,NULL,foo,NULL);
	if(ret != 0)
	{
		perror("pthread create failed!\n");
		exit(-1);
	}
	pthread_detach(tid);
	printf("master done!\n");
	sleep(5);
	return 0;
}

