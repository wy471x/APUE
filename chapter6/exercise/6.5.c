#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t;
    struct tm *tmp;
    char buf[64];
    time(&t);

    if( putenv("TZ=UTC") == -1)
        perror("putenv error");
    tmp = localtime(&t);
    if(strftime(buf, 64, "%a %b %d %T %Z %Y", tmp) == 0)
        printf("buffer length 16 is too small\n");
    else
        printf("%s\n", buf);
    return 0;
}

