#include "my.h"
int main()
{
	FILE *fp;
	fp = fopen("out.dat","w+");
	int pid1,pid2,pid3,status,rv;
	pid1=fork();
	if(pid1<0){
		printf("fork1 failed!\n");
		return -1;
	}else if(pid1 == 0){
		for(int i = 1;i <= 10;i++){
			fprintf(fp,"pid=%d,%d\n",getpid(),i);
		}
		printf("child1 pid = %d\n",getpid());
		sleep(3);
		exit(18);
	}else{
		pid2=fork();
		if(pid2<0){
			printf("fork2 failed!\n");
			return -1;
		}else if(pid2 == 0){
			for(int i = 1;i <= 10;i++){
				fprintf(fp,"pid=%d,%d\n",getpid(),i);
			}
			printf("child2 pid = %d\n",getpid());
			sleep(5);
			exit(99);
		}else{
			pid3=fork();
			if(pid3<0){
				printf("fork3 failed!\n");
				return -1;
			}else if(pid3 == 0){
				for(int i = 1;i <= 10;i++){
					fprintf(fp,"pid=%d,%d\n",getpid(),i);
				}
				printf("child3 pid = %d\n",getpid());
				sleep(2);
				exit(108);
			}else{
				char buf[4096];
				printf("parent waiting child end!\n");
				rv = wait(&status);
				printf("1:child %d end,exit code is %d\n",rv,WEXITSTATUS(status));
				rv=0;
				status=0;
				rv = waitpid(pid1,&status,0);
				printf("2:child %d end,exit code is %d\n",rv,WEXITSTATUS(status));
				rv=0;
				status=0;
				rv = waitpid(pid2,&status,WNOHANG);
				printf("3:child %d end,exit code is %d\n",rv,WEXITSTATUS(status));
				fseek(fp,0,SEEK_SET);
				fread(buf,4096,1,fp);
			    printf("%s\n",buf);	
				fclose(fp);
			}
		}
	}
	return 0;
}
