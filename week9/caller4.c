#include "my.h"
int main()
{
	char *arg[]={"./test1","123","hello","World",NULL};	
	printf("caller3 pid =%d,ppid=%d\n",getpid(),getppid());
	execv("/home/rlk/week9/test1",arg);
	printf("execl after calling!\n");
	return 0;
}
