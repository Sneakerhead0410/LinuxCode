#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	FILE*fp;
	int i = 0;
	if((fp = fopen("check.txt","w+")) == NULL){
		perror("fail to fopen!");
		return -1;
	}
	pid = vfork();
	if(pid < 0){
		perror("fial to fork");
		return -1;
	}
	else if (pid == 0){
		for(;i<=10;i++){
			fprintf(fp,"child: i = %d,fp = %d\n", i,fileno(fp));
		}
		fclose(fp);
	}
	else  {
		for(;i<=20;i++){
			fprintf(fp,"parent: i = %d, fp = %d\n", i,fileno(fp));
		}
		fclose(fp);
	}	
//fclose(fp);
	return 0;
}

