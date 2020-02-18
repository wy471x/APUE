#include "../../include/apue.h"
#define MAXSIZE 100
void test1(){
    char buf[MAXSIZE] = {0};
    while(fgets(buf, MAXSIZE, stdin) != NULL){
        printf("buf = ");
        fputs(buf, stdout);
    }
}

int main()
{
    test1();
    return 0;
}

