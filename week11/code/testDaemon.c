#include "my.h"
#include <time.h>
void init_daemon(void);
int main()
{
	FILE *fp;
	time_t t;
	init_daemon();
	while(1){
		sleep(10);
		if((fp = fopen("testDaemon.log","a")) >= 0){
			t = time(0);
			fprintf(fp,"daemon is running, time is: %s",asctime(localtime(&t)));
			fclose(fp);
		}
	}
	return 0;
}
