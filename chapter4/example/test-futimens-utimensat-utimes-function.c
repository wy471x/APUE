#include "../../include/apue.h"
#include <fcntl.h>
void test1(){
    int fd;
    if((fd = open("fu_file", O_RDWR|O_TRUNC)) < 0)
        err_ret("fu_file: open error.");
    if(futimens(fd, NULL) < 0)
        err_ret("fu_file: futimens error.");
    printf("futimens changes.\n");
    close(fd);
}
void test2(){
    if(utimensat(AT_FDCWD, "ut_file", NULL, AT_SYMLINK_NOFOLLOW) < 0)
        err_ret("ut_file: utimensat error.");
    printf("utimensat changes.\n");
}
int main()
{
    test1();
    test2();
    return 0;
}

