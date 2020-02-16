#include "../../include/apue.h"
/*
    five situations for rename call.
*/
//  1. oldname points to a file, not directory.
//   newname has existed and is not a directory.
void test_file()
{
    if(rename("oldfile","newfile") < 0)
        err_sys("rename failed");
    printf("rename success!\n");
}
// 2. oldname points to a directory.
// newname has existed and is a directory too.
void test_directory()
{
    if(rename("olddir", "newdir") < 0)
        err_sys("rename failed");
    printf("rename success!\n");
}
// 3. oldname points to symbol link.
void test_symbollink()
{
    if(rename("oldfilep", "newfilep") < 0)
        err_sys("rename failed");
    printf("rename success!\n");
}
int main(void)
{
    test_file();
    test_directory();
    test_symbollink();
    return 0;
}
