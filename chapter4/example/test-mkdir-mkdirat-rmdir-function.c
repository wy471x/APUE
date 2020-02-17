#include "../../include/apue.h"
#include <fcntl.h>
void test1(){
    if(mkdir("mkdirfile", 0775) < 0)
        err_sys("mkdir error.");
    printf("mkdir success.\n");
}
void test2(){
    if(mkdirat(AT_FDCWD, "mkdiratfile", 0775) < 0)
        err_sys("mkdirat error.");
    int fd;
    printf("mkdirat success.\n");
    if((fd=open("../exercise", O_RDONLY)) < 0)
        err_sys("open error.");
    if(mkdirat(fd, "mkdiratfile2", 0755) < 0)
        err_sys("mkdirat error.");
    printf("mkdirat success.\n");
    close(fd);
}
void test3(){
    if(rmdir("mkdirfile") < 0)
        err_sys("rmdir error.");
    printf("rmdir success.\n");
}
int main()
{
    //test1();
    //test2();
    test3();
    return 0;
}

