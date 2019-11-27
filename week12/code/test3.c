#include "my.h"
int main()
{
	int pid1,pid2,pid3;
	int status1,status2,status3;
	int r1,r2,r3;
	int p1[2],p2[2];
	int rn,wn;
	pipe(p1);
	pipe(p2);
	pid1=fork();
	if(pid1<0){
		printf("fork1 failed!\n");
		return -1;
	}else if(pid1 == 0){
		close(p2[0]);
		close(p2[1]);
		close(p1[0]);
		printf("[child1: %d] is running,[parent] is %d\n",getpid(),getppid());
		for(int i = 0;i <= 65535;i++){
			write(p1[1],&i,sizeof(i));	
		}
		close(p1[1]);
		exit(8);
	}else{
		pid2=fork();
		if(pid2<0){
			printf("fork2 failed!\n");
			return -1;
		}else if(pid2 == 0){
			close(p1[1]);
			close(p2[0]);
			int n;
			printf("[child2: %d] is running,[parent] is %d\n",getpid(),getppid());
			for(int i = 0;i <= 65535;i++){
				read(p1[0],&n,sizeof(n));
				write(p2[1],&n,sizeof(n));
			}
			close(p2[1]);
			close(p1[0]);
			exit(88);
		}else{
			pid3=fork();
			if(pid3<0){
				printf("fork3 failed!\n");
				return -1;
			}else if(pid3 == 0){
				close(p1[0]);
				close(p1[1]);
				close(p2[1]);
				int sum = 0,n;
				printf("[child3: %d] is running,[parent] is %d\n",getpid(),getppid());
				for(int i = 0;i <= 65535;i++){
					read(p2[0],&n,sizeof(n));
					sum += n;
				}
				close(p2[0]);
				printf("[child3: %d],sum is %d\n",getpid(),sum);
				exit(108);
			}else{
				r1 = wait(&status1);
				r2 = wait(&status2);
				r3 = wait(&status3);
				printf("[parent: %d] is running\n",getpid());
				printf("child1 %d is finished,return code = %d\n",r1,WEXITSTATUS(status1));
				printf("child2 %d is finished,return code = %d\n",r2,WEXITSTATUS(status2));
				printf("child3 %d is finished,return code = %d\n",r3,WEXITSTATUS(status3));
				return 0;
			}
		}
	}
	return 0;
}
