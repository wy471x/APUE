#include <func.h>

int main()
{
    int fd1 = open("file1",O_RDONLY);
    int fd3 = dup(fd1);
    int fd2 = open("file1",O_RDONLY);
    printf("fd1 = %d, fd2 = %d, fd3 = %d\n", fd1, fd2, fd3);
    return 0;
}

