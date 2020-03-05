#include "apue.h"
#include <fcntl.h>

int main(void)
{
    char buf[MAXLINE];
    int fdFifo = open("myfifo", O_RDONLY);
    if(read(fdFifo, buf, sizeof(buf)) > 0)
        puts(buf);
    close(fdFifo);
    return 0;
}

