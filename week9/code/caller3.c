#include "my.h"

int main()
{
	printf("caller3: pid=%d, ppid = %d\n",getpid(),getppid());
	execl("/home/rlk/linuxCode/week9/test1","./test1","123","hello","world",NULL);
	printf("execl after calling\n");
	return 0;

}
