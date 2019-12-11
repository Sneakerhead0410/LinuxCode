#include "my.h"


void * fun(void *arg)
{
	struct Cal *cals = (struct Cal *)arg;
	int sum = 0;
	int i;
	for(i = 1;i <= cals->max;i++)
		sum += i;
	printf("Woker-----%d: sum = %d. pthread_self %p\n",cals->i,sum,(void *)pthread_self());
	pthread_exit(NULL);
	return NULL;
}


int main()
{
	struct Cal cal;
	pthread_t tid[NUM];
	int ret[NUM],i;
	for(i = 0;i < NUM;i++){
		cal.i = i+1;
		cal.max = (i+1) * 100;
		ret[i] = pthread_create(&tid[i],NULL,fun,(void *)&cal);
		if(ret[i] != 0){
			perror("Create failed!\n");
			return -1;
		}
	}
	for(i = 0;i < NUM;i++){
		pthread_join(tid[i],NULL);
	}
	printf("Master %d: All Done!\n",getpid());
	return 0;
}
