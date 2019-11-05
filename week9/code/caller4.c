#include "my.h"

int main()
{
	char *arg[]= {"./test1","123","hello","world",NULL};
	printf("caller4: pid=%d, ppid = %d\n",getpid(),getppid());
	execv("/home/rlk/linuxCode/week9/test1",arg);
	printf("execl after calling\n");
	return 0;

}
