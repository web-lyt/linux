#include "my.h"
void sighandler(int);
int main()
{	
	int fd[2];
	pid_t pid;
	if(signal(SIGPIPE,sighandler)==SIG_ERR)
	{
		fprintf(stderr,"signal error [%s]\n",strerror(errno));
	}	
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"create pipe error.reason:[%s]\n",strerror(errno));
	}
	pid = fork();
	if(pid<0)
	{
		fprintf(stderr,"create child error.reason:[%s]\n",strerror(errno));
		close(fd[0]);
		return -2;
	}

	else if(pid==0)
	{
		close(fd[0]);
		wait(NULL);
		int ret;		
		printf("[child]:pid=%d,ppid=%d\n",getpid(),getppid());
				
		sleep(50);
		exit(0);	
	}
	else
	{
		close(fd[0]);
		wait(NULL);
		int ret;
		ret=write(fd[1],"hello",5);
		if(ret==-1)
		{
			printf("[parent]:write failed! error reason:[%s]\n",strerror(errno));
		}	
	} 
}


void sighandler(int signo)
{
	printf("[parent]:write catch SIGPIPE signal and aisnumber = %d\n",signo);

}
