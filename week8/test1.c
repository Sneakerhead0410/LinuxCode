#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[],char *env[])
{
	/* method 1
		int i = 0;
		for(;env[i];i++)
		{
			printf("%s\n",env[i]);
		}
		return 0;
	*/


	/* method 2 
		extern char **environ;
		int i = 0;
		for(; environ[i];i++)
		{
			printf("%s\n",environ[i]);
		}
		return 0;
	*/
	
	/* method 3 */
		printf("%s\n",getenv("PATH"));
		return 0;

}
