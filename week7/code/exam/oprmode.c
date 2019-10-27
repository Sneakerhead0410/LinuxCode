#include "myhead.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>	
#include <sys/stat.h>	
void CheckFileMode_1(char *path)
{
	int ret;
	struct stat statbuf;
	mode_t mode;
	int user;
	int group;
	int other;
	int temp,i,j;
	
	ret = stat(path,&statbuf);
	if(ret < 0){
		printf("get file information failed!\n");
	}
	printf("%s mode: ",path);
	mode =  statbuf.st_mode;
	if(S_ISDIR(mode))
		printf("d");
	else
		printf("-");
	for(j = 3;j >= 1;j--){
	temp = mode >> (j-1)*3;
		for(i = 1;i <= 3;i++){
			switch(i){
				case 1:
					if(temp & (1 << 2))
						printf("r");
					else
						printf("-");
					break;
				case 2:
					if(temp & (1 << 1))
						printf("w");
					else
						printf("-");
					break;
				case 3:
					if(temp & 1)
						printf("x");
					else
						printf("-");
					break;
				default:
					break;
			}
		}
			
	}	
	printf("\n");
	
}



void ChangeFileMode_1(char * path,int mode)
{
	int changeMode;
	int mode_u,mode_g,mode_o;
	if ((mode > 777) || (mode < 0))
    {
        printf("mode num error!\n");
        exit(0);
    }
	mode_u = mode / 100;
    mode_g = mode / 10 % 10;
    mode_o = mode % 10;
    changeMode = (mode_u * 8 * 8) + (mode_g * 8) + mode_o;
	if(chmod(path,changeMode) == -1)
	{
		perror("chmod error\n");
        exit(1);  
	}else{
		printf("chmod sucess!\n");
	}
   
}
