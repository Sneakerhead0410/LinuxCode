#include "my.h"

int g = 10;
int main()
{
	int status;
	int l = 20;
	static int s = 30;
	pid_t pid;
	pid = vfork();
	if(pid < 0)
	{
		perror("failed to fork!\n");
		return -1;
	}
	else if(pid == 0)
	{
	//	int p = 99;
		printf("-----address of vara-----\n");
		printf("child pid = %d:\n&g=%16p\n&t=%16p\n&s=%16p\n",getpid(),&g,&l,&s);
		g = 100;
		l = 200;
		s = 300;
//	    p = 99999;
		execl("./test5","test5",NULL);
		printf("value in child\n");
		printf("child: \ng=%d\nl=%d\ns=%d\n",g,l,s);
		return 0;
//		exit(119);
//		_exit(0);
}
	else
	{
	//	wait(&status);	
	//	printf("parent: exit code from child is %d\n",WEXITSTATUS(status));
		printf("-----address of vara-----\n");
		printf("parent:\n&g=%16p\n&t=%16p\n&s=%16p\n",&g,&l,&s);
		printf("value in parent\n");
		printf("parent: \ng=%d\nl=%d\ns=%d\n",g,l,s);
		return 0;
	}
}
