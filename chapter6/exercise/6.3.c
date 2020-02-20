#include <sys/utsname.h>
#include <stdio.h>
void test()
{
    struct utsname name;
    if(uname(&name) < 0)
        perror("uname error");
    printf("sysname = %s, nodename = %s, release = %s, version = %s, machine = %s\n",\
           name.sysname, name.nodename, name.release, name.version, name.machine);

}
int main()
{
    test();
    return 0;
}

