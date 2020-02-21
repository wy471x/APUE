#include "../../include/apue.h"
#include <setjmp.h>

#define TOK_ADD 5

void do_line(char *);
void cmd_add(void);
int get_token(void);

jmp_buf jmpbuffer;

int main(void)
{
    char line[MAXLINE];
    int n;
    if((n = setjmp(jmpbuffer)) != 0)
        printf("error, n = %d", n);
    while(fgets(line, MAXLINE, stdin) != NULL)
        do_line(line);
    return 0;
}

char *tok_ptr;

void do_line(char *ptr)
{
    int cmd;
    tok_ptr = ptr;
    while((cmd = get_token()) > 0){
        switch(cmd){
        case TOK_ADD:
                cmd_add();
                break;
        }
    }
}

void cmd_add(void)
{
    int token;

    token = get_token();

    if(token < 0)
    {
        longjmp(jmpbuffer, 1);
    }
}

int get_token(void)
{
    /* fetch next token from line pointed to by tok_ptr */
    //int i = -1;
    //if(i < 0)
    //    longjmp(jmpbuffer, 2);

    return 5;
}
