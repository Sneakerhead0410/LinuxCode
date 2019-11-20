#include "my.h"
int main()
{
	int status,r;
	pid_t pid;
	pid = fork();
	if(pid < 0){
		perror("failed fork!");
		return -1;	
	}else if(pid == 0){
		printf("child %d is running!\n",getpid());
		printf("child wait exit!\n");
		exit(120);
	}else{
		printf("parent waiting child  %d to exit\n",pid);
		r=wait(&status);
		printf("child %d is finished,return code = %d\n",r,WEXITSTATUS(status));
		printf("parent %d is running:\n",getpid());
	}
	return 0;
}
