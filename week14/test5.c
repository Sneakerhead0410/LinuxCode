#include "my.h"

void *fun(void *arg)
{
	int TID = pthread_self();
	//syscall(SYS-gettid);
	printf("Woker-----%d: gettid return %d\n",TID,TID);
	printf("Woker-----%d: gettid return %p\n",TID,(void *)pthread_self);
	printf("Woker-----%d: will exit!\n",TID);
	pthread_exit(NULL);
	return NULL;
}

int main()
{
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid,NULL,fun,NULL);
	if(ret != 0){
		perror("Create failed!\n");
		return -1;
	}
	pthread_join(tid,NULL);
	ret = pthread_create(&tid,NULL,fun,NULL);
	if(ret != 0){
		perror("Create failed!\n");
		return -1;
	}
	pthread_join(tid,NULL);
	printf("Master %d: All Done!\n",getpid());
}
