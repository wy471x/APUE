#include "../../include/apue.h"
#include <sys/wait.h>

static void sig_int(int);
static void sig_chld(int);
int system(const char *);

int main()
{
    if(signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal(SIGINT) error");
    if(signal(SIGCHLD, sig_chld) == SIG_ERR)
        err_sys("signal(SIGCHLD) error");

    if(system("/bin/ed") < 0)
        err_sys("system() error");

    return 0;
}

static void sig_int(int signo)
{
    printf("caught SIGINT\n");
}

static void sig_chld(int signo)
{
    printf("caught SIGCHLD\n");
}

int system(const char *cmdstring) /* with appropriate signal handling */
{
    pid_t pid;
    int status;
    struct sigaction ignore, saveintr, savequit;
    sigset_t chldmask, savemask;

    if(cmdstring == NULL)
        return (1);

    ignore.sa_handler = SIG_IGN;    /* ignore SIGINT and SIGQUIT */
    sigemptyset(&ignore.sa_mask);
    ignore.sa_flags = 0;
    if(sigaction(SIGINT, &ignore, &saveintr) < 0)
        return (-1);
    if(sigaction(SIGQUIT, &ignore, &savequit) < 0)
        return (-1);
    sigemptyset(&chldmask);
    sigaddset(&chldmask, SIGCHLD);
    if(sigprocmask(SIG_BLOCK, &chldmask, &savemask) < 0)
        return (-1);

    if((pid = fork()) < 0){
        status = -1;
    }else if(pid == 0){
        sigaction(SIGINT, &saveintr, NULL);
        sigaction(SIGQUIT, &savequit, NULL);
        sigprocmask(SIG_SETMASK, &savemask, NULL);

        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);
    }else{
        while(waitpid(pid, &status, 0) < 0)
            if(errno != EINTR){
                status = -1;
                break;
            }
    }

    if(sigaction(SIGINT, &saveintr, NULL) < 0)
        return (-1);
    if(sigaction(SIGQUIT, &savequit, NULL) < 0)
        return (-1);
    if(sigprocmask(SIG_SETMASK, &savemask, NULL) < 0)
        return (-1);

    return (status);
}
