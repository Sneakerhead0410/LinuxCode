#include "my.h"

int main()
{
	int ret;
	printf("caller1: pid = %d,ppid = %d \n",getpid(),getppid());
	ret = system("./test2 123456 hello world");
	printf("After calling !\n");
	sleep(100);
	printf("ret = %d\n",ret);
	return 0;
}
