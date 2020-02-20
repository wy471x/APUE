#include "../../include/apue.h"
void test()
{
    char name[100];
    memset(name, 0, sizeof(name));
    if(gethostname(name, 100) < 0)
        err_sys("gethostname error");
    printf("host name = %s\n", name);
}
int main()
{
    test();
    return 0;
}

