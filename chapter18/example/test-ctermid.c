#include "apue.h"

int main(void)
{
    char buf[256];
    memset(buf, 0, sizeof(buf));

    strcpy(buf,ctermid(NULL));
    printf("buf = %s\n", buf);
    exit(0);
}
