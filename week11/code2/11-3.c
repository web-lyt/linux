#include "my.h"
void init_demon(void)
{
	pid_t p;
	int i;
	p=fork();
	if(p>0)
		exit(0);
	else if(p<0)
	{
		perror("fork failed!\n");
		return -1;
		
	}
	setsid();
	chdir("/tmp");
	umask(0);
	for(i=0;i<NOFILE;i++)
	{
		close();
	}	
}
