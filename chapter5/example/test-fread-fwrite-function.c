#include "../../include/apue.h"
void test1()
{
    FILE *fp;
    if((fp=fopen("fopenfile", "w+")) == NULL){
        perror("fopen error.");
        exit(1);
    }
    float data[10] = {0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    if(fwrite(&data[2], sizeof(float), 4, fp) != 4)
        err_sys("fwrite error");
    rewind(fp);
    float buf[4] = {0};
    fread(buf, sizeof(float), 4, fp);
    for(int i = 0; i < 4; i++)
        printf("%.1f\n", buf[i]);
}
#define NAMESIZE 255
typedef struct {
    short count;
    long total;
    char name[NAMESIZE];
}item;
void test2()
{
    FILE *fp;
    if((fp=fopen("fopenfile2","w+")) == NULL)
        perror("fopen error");
    item i = {12, 255, "dunkwan"};
    if(fwrite(&i, sizeof(item), 1, fp) != 1)
    {
        err_sys("fwrite error");
    }
    rewind(fp);
    item j;
    memset(&j, 0, sizeof(item));
    fread(&j, sizeof(item), 1, fp);
    printf("%d %ld %s\n", j.count, j.total, j.name);
}
int main(void)
{
     test2();
     exit(0);
}
