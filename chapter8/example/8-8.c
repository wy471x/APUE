#include "../../include/apue.h"
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    if((pid=fork()) < 0){
        err_sys("fork error");
    }else if(pid == 0)
    {
        if((pid = fork()) < 0)
            err_sys("fork error");
        else if(pid > 0){
                sleep(1);
                printf("second pid = %ld\n", (long)pid);
                exit(0);
        }
        
        printf("second ppid = %ld\n", (long)getppid());
        sleep(2);
        printf("second child, parent pid = %ld, pid = %ld\n", 
               (long)getppid(), (long)getpid());
        exit(0);
    }

    if(waitpid(pid, NULL, 0) != pid)
        err_sys("waitpid error");
    printf("first pid = %ld\n", (long)pid);
    return 0;
}

