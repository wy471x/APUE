#include "../../include/apue.h"
#include <fcntl.h>
void test1(){
    if(symlink("actualpath", "sympath") < 0)
        err_sys(" symlink error.");
    printf("symlink success.\n");
}
void test2(){
    if(symlinkat("actualpath2", AT_FDCWD, "sympath2") < 0)
        err_sys(" symlinkat error.");
    printf("symlinkat success.\n");
}
int main(void)
{
    test1();
    test2();
    return 0;
}

