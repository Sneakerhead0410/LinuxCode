#include <stdio.h>
#include <stdlib.h>
#include "myhead.h"
#define MAX 50
#define BUFFERMAX 1024
int  main()
{
	char ch,back;
	char path[MAX];
	char buffer[BUFFERMAX];
	int  mode;
	system("reset");
	while(1){
		printf("****************************\n");
		printf("0.Exit \n");
		printf("1.Create mew file \n");
		printf("2.Write to file \n");
		printf("3.Read from file \n");
		printf("4.Change file mode \n");
		printf("5.Check file mode \n");
		printf("****************************\n");
		printf("Please input your chioce(0~5):");
		ch = getchar();
		getchar();
		switch(ch){
			case '0': 
					exit(0);
					break;
			case '1':
					printf("Please input file's path you will create:");
					scanf("%s",path);
					getchar();
					CreateFile_1(path);
					printf("\n\n\nPress any key back to the menu\n");
					getchar();
					break;
			case '2':
					printf("Please input file's path to which you will write:");
					scanf("%s",path);
					getchar();
					printf("Please input content:");
					gets(buffer);
					WriteToFile_1(path,buffer);
					printf("\n\n\nPress any key back to the menu\n");
					getchar();
					break;
			case '3':
					printf("Please input file's path from which you will read:");
					scanf("%s",path);
					getchar();
					printf("the content of file(%s):\n",path);
					printf("%s \n",ReadFromFile_1(path));
					printf("\n\n\nPress any key back to the menu\n");
					getchar();
					break;
			case '4':
					printf("Please input file's path:");
					scanf("%s",path);
					printf("Please input mode(0~777):");
					scanf("%d",&mode);
					ChangeFileMode_1(path,mode);
					getchar();
					printf("\n\n\n Press any key back to the menu\n");
					getchar();
					break;
			case '5':
					printf("Please input file's path:");
					scanf("%s",path);
					CheckFileMode_1(path);
					getchar();
					printf("\n\n\nPress any key back to the menu\n");
					getchar();
					break;
			default:break;
		}
		system("reset");
	}
	return 0;
}
