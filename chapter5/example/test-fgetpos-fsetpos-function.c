#include "../../include/apue.h"
void test()
{
    FILE *fp;
    if((fp=fopen("fgfsfile", "w+")) == NULL)
        perror("fopen error");
    fseek(fp, 255, SEEK_CUR);
    fpos_t *p =(fpos_t *)malloc(sizeof(fpos_t));
    fgetpos(fp, p);
    char buf[100] = "hello world!";
    fwrite(buf, 1, strlen(buf), fp);
    fsetpos(fp, p);
    char res[100];
    memset(res, 0,sizeof(res));
    fread(res, 1, sizeof(res), fp);
    printf("res = %s\n", res);
}

int main()
{
    test();
    return 0;
}

