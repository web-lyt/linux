
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
 
#define ERR_EXIT(m) \
        do \
        { \
                perror(m); \
                exit(EXIT_FAILURE); \
        } while(0)
 
int main(int argc,char* argv[])
{
        signal(SIGCHLD,SIG_IGN);
        int ret;
        int var;
        var = 1;
        if ((ret = vfork()) > 0)
        {
                printf("parent start...\n");
                printf("var=%d\n",var);
        }
        else if(ret == 0)
        {
                sleep(3);
                var = 3;
                _exit(0);
        }
        return 0;

}

