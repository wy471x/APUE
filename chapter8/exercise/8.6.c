#include "../../include/apue.h"

int main()
{
    pid_t pid;

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0){
        printf("this child process...\n");
        exit(2);
    }

    sleep(2);
    char buf[100];
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "ps %d", pid);

    system(buf);

    return 0;
}

