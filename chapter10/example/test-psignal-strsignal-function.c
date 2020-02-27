#include <stdio.h>
#include <signal.h>
#include <string.h>
void test_psignal()
{
    psignal(SIGINT, "SIGINT error");
}

void test_strsignal()
{
    char *buf = strsignal(SIGALRM);
    printf("buf = %s\n", buf);
}

void test_psiginfo()
{

}

int main()
{
    test_psignal();
    test_strsignal();
    return 0;
}

