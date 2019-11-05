#include "my.h"
int main()
{
	printf("caller3 pid =%d,ppid=%d\n",getpid(),getppid());
	execl("/home/rlk/week9/test1","./test1","123","hello","World",NULL);
	printf("execl after calling!\n");
	return 0;
}
