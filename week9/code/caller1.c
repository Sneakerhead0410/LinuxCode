#include "my.h"

int main()
{
	int ret;
	printf("caller1: pid = %d,ppid = %d \n",getpid(),getppid());
	ret = system("./test1 123456 hello world");
	printf("After calling !\n");
	return 0;
}
