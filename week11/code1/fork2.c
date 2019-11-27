#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char* filename = "test.bin";
    pid_t pid = fork();
    if(0==pid){
        printf("this is child: %ld\n", (long)getpid());
        char buf[20];
        memset(buf, 1, sizeof(buf));
        int fd = open(filename, O_WRONLY|O_CREAT);
        write(fd, buf, sizeof(buf));
        close(fd);
    }else{
		usleep(500);
        printf("this is father: %ld\n", (long)getpid());
        char buf[30] = {2};
        memset(buf, 2, sizeof(buf));
        int fd = open(filename, O_WRONLY|O_CREAT);
        write(fd, buf, sizeof(buf));
        close(fd);
        int status;
        wait(&status);
    }
    return 0;
}
