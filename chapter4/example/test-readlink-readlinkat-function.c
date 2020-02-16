#include "../../include/apue.h"
#include <fcntl.h>
void test1(){
    char buf[20];
    if(readlink("sympath", buf, 20) < 0)
        err_sys("readlink error.");
    printf("readlink success: %s\n",buf);
}
void test2(){
    char buf[20];
    if(readlinkat(AT_FDCWD, "sympath2", buf, 20) < 0)
        err_sys("readlinkat error.");
    printf("readlinkat success: %s\n", buf);
}
int main()
{
    test1();
    test2();
    return 0;
}

