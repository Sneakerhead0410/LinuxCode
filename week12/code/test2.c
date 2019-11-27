#include "my.h"

int main()
{
	pid_t p;
	int fd[2],rn,wn;
	char r_buf[1],w_buf[30];
	memset(r_buf,0,sizeof(r_buf));
	memset(w_buf,0,sizeof(w_buf));
	pipe(fd);
	p = fork();
	if(p<0){
		perror("fork failed.\n");
		return -1;	
	}else if(p==0){
		close(fd[0]);
		sprintf(w_buf,"1");
		for(int i = 0;i < 65537;i++)
			write(fd[1],w_buf,sizeof(w_buf));
		close(fd[1]);
		exit(8);
	}else{
		wait(NULL);
		close(fd[1]);
		while(1)
		{
			rn = read(fd[0],r_buf,sizeof(r_buf));
			printf("[parent] read from pipe %d byte.Content of pipe is %s\n",rn,r_buf);
			if(rn==0){
				printf("[parent] read error.\n");
				break;	
			}
		}
		close(fd[0]);
		exit(8);
		
	}
	return 0;
}





































