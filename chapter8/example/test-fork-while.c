#include <func.h>

int main()
{
    pid_t pid;
    while((pid = fork()) == 0){
        printf("child pid = %ld", (long)getpid());
    }
    return 0;
}

