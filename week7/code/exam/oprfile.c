#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "myhead.h"

void CreateFile_1(char *path)
{	
	int fd;
	if((fd=creat(path,0664)) <0)
	{
	 	perror("Create failed\n");
		exit(1);
	}
	printf("Create file success,path and name: %s\n",path);
	close(fd);
}

void WriteToFile_1(char *path,char *buf)
{	
	FILE *fp;
	if((fp = fopen(path,  "wb+")) == NULL)	
	{
	 	perror("open file failed\n");
		exit(1);
	}
	fwrite(buf,sizeof(char),strlen(buf),fp);
	fclose(fp);
	printf("write sucess!\n");
}

char* ReadFromFile_1(char *path)
{
	FILE *fp;
	int size;
	char *buffer;
	if((fp = fopen(path, "rb")) == NULL)
	{
	 	perror("open file failed\n");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);  
    size = ftell(fp);  
    rewind(fp);  
	buffer = (char *)malloc(sizeof(char) * size);
	fread(buffer,sizeof(char),size,fp);
	fclose(fp);
	return buffer;
}
