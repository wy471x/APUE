#include "../../include/apue.h"
static char databuf[BUFSIZ];
FILE *open_data(void);
int test(FILE *);

int main()
{
    FILE *fp = open_data();
    int i = test(fp);
    printf("i = %d\n", i);
    return 0;
}

FILE *open_data(void)
{
    FILE *fp;
    //char databuf[BUFSIZ];

    if((fp = fopen("datafile", "r")) == NULL)
        return NULL;
    if(setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0)
        return NULL;
    return (fp);
}

int test(FILE *fp)
{
    char buf[100];
    memset(buf, 0, sizeof(buf));
    fgets(buf, 100, fp);
    printf("databuf = %s", databuf);
    return 1;
}
