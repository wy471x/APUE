#include "apue.h"
void err_ret(const char*fmt,...){
    va_list ap;

    va_start(ap,fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);

}

void err_sys(const char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    err_doit(1,errno, fmt,ap);
    va_end(ap);
    exit(1);

}

    void  
err_exit(int error, const char *fmt, ...)  
{  
    va_list     ap;  

    va_start(ap, fmt);  
    err_doit(1, error, fmt, ap);  
    va_end(ap);  
    exit(1);  


}  

    void  
err_dump(const char *fmt, ...)  
{  
    va_list     ap;  

    va_start(ap, fmt);  
    err_doit(1, errno, fmt, ap);  
    va_end(ap);  
    abort();        /* dump core and terminate */  
    exit(1); 
}  

    void  
err_msg(const char *fmt, ...)  
{  
    va_list     ap;  

    va_start(ap, fmt);  
    err_doit(0, 0, fmt, ap);  
    va_end(ap);  
}  

    void  
err_quit(const char *fmt, ...)  
{  
    va_list     ap;  

    va_start(ap, fmt);  
    err_doit(0, 0, fmt, ap);  
    va_end(ap);  
    exit(1);  


}  

    static void  
err_doit(int errnoflag, int error, const char *fmt, va_list ap)  
{  
    char    buf[MAXLINE];  
    vsnprintf(buf, MAXLINE, fmt, ap);  
    if (errnoflag)  
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s\n",strerror(error));  
    fflush(stdout);     /* in case stdout and stderr are the same */  
    buf[strlen(buf)] = '\n';
    fputs(buf, stderr);  
    fflush(NULL);       /* flushes all stdio output streams */  
}
