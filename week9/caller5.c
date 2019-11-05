#include "my.h"

int main()
{
	char *arg[]= {"./test1","123","hello","world",NULL};
	printf("caller5: pid=%d, ppid = %d\n",getpid(),getppid());
	execlp("./test1","123","hello","world",NULL);
//	execv("/home/rlk/linuxcode/week9",arg);
	printf("execl after calling\n");
	return 0;

}
