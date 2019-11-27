#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
 
int main(void)
{
	pid_t pid  = -1;
	int fd = -1;
	
	fd = open("1.txt", O_TRUNC | O_RDWR);
	if(fd < 0)
	{
		perror("open");
		exit(-1);
	}
	
	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return -1;
	}
	else if(pid == 0)
	{
		printf("这里是子进程.\n");
		write(fd, "world", 5);		
		//printf("pid = %d.\n", pid);	
		//printf("子进程中的父进程id = %d.\n", getppid());	
		//sleep(1);
	}
	else
	{
		printf("这里是父进程.\n");	
		write(fd, "hello", 5);		
		//printf("pid = %d.\n", pid);	
		//sleep(1);
	}
	//printf("这一句是否打印两次pid = %d.\n",getpid());
	
	return 0;
}

