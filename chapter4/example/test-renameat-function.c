#include "../../include/apue.h"
#include <fcntl.h>
void test_file()
{
    if(renameat(AT_FDCWD, "oldfile2", AT_FDCWD, "newfile2") < 0)
        err_sys("renameat failed!");
    printf("renameat success!\n");
}
int main(void)
{
    test_file();
    return 0;
}

