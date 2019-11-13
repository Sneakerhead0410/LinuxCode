#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	FILE*fp;
	int i;
	if((fp = fopen("check.txt","w+")) == NULL){
		perror("fail to fopen!");
		return -1;
	}
	pid = fork();
	if(pid < 0){
		perror("fial to fork");
		return -1;
	}
	else if (pid == 0){
		for(i =1;i<=10;i++){
			fprintf(fp,"child: i = %d,fd = %d \n",i,fileno(fp));
		}
		fclose(fp);
	}
	else  {
		for(i =1;i<=20;i++){
			fprintf(fp,"parent: i = %d,fd = %d \n", i,fileno(fp));
		}
		fclose(fp);
	}
//fclose(fp);
	return 0;
}

