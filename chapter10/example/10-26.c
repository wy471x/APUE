#include "../../include/apue.h"
#include <sys/wait.h>
#include <unistd.h>

int system(const char *);
static void sig_int(int);
static void sig_chld(int);

int main(void)
{
    if(signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal(SIGINT) error");
    if(signal(SIGCHLD, sig_chld) == SIG_ERR)
        err_sys("signal(SIGCHLD) error");
    if(system("/bin/ed") < 0)
        err_sys("system() error");
    return 0;
}

int system(const char *cmdstring)   /* version without signal handling */
{
    pid_t   pid;
    int     status;

    if (cmdstring == NULL)
        return(1);      /* always a command processor with UNIX */

    if ((pid = fork()) < 0) {
        status = -1;    /* probably out of processes */

    } else if (pid == 0) {              /* child */
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);     /* execl error */
    } else {                            /* parent */
        while (waitpid(pid, &status, 0) < 0) {
            if (errno != EINTR) {
                status = -1; /* error other than EINTR from waitpid() */
                break;

            }

        }
    }

    return(status);
}

static void sig_int(int signo)
{
    printf("caught SIGINT\n");
}

static void sig_chld(int signo)
{
    printf("caught SIGCHLD\n");
}
