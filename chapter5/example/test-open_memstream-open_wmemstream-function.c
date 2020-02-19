#include "../../include/apue.h"
#include <wchar.h>
#define MAXSIZE 40
void test1()
{
    FILE *fp;
    char *buf = (char *)malloc(MAXSIZE*sizeof(char));
    memset(buf, 'a', MAXSIZE-2);
    buf[MAXSIZE-2] = '\0';
    buf[MAXSIZE-1] = 'X';
    printf("buf = \"%s\", len = %ld\n", buf, (long)strlen(buf));
    size_t size = MAXSIZE;
    if((fp = open_memstream(&buf, &size)) == NULL)
        err_sys("open_memstream error");
    fprintf(fp, "hello, world");
    printf("before flush buf = \"%s\", len = %ld\n", buf, (long)strlen(buf));
    fflush(fp);
    printf("after flush buf = \"%s\", len = %ld\n", buf, (long)strlen(buf));
}

int main()
{
    test1();
    return 0;
}

