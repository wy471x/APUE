#include "apue.h"
#include <fcntl.h>
int main(void)
{
    int fdFifo = open("myfifo", O_WRONLY);
    if(write(fdFifo, "hello world!", 12) < 0)
        err_sys("write error");
    close(fdFifo);
    return 0;
}

