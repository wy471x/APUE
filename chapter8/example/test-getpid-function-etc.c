#include "../../include/apue.h"

int main()
{
    pid_t pid, ppid;
    uid_t uid, euid;
    gid_t gid, egid;
    
    printf("pid = %d, ppid = %d, uid = %d, euid = %d, gid = %d, egid = %d\n", 
           pid = getpid(), ppid = getppid(), uid = getuid(), euid = geteuid(), 
           gid = getgid(), egid = getegid());

    return 0;
}

