#include "apue.h"
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#define PATH "/tmp/shm-sem"
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main(void)
{
    key_t key = ftok(PATH, 0);
    int semid = semget(key, 2, IPC_CREAT|0666);
    if(semid < 0)
        err_sys("semget error");
    int fd;
    if((fd = open(PATH, O_WRONLY)) < 0)
        err_sys("open error");
    int ret;
    if((ret = write(fd, &key,  sizeof(key))) < 0)
        err_sys("write error");
    int shmid = shmget(key, 1024 * 1024, IPC_CREAT|0666);
    if(shmid < 0)
        err_sys("shmget error");
    
    union semun arg;
    arg.val = 0;
    semctl(semid, 0, SETVAL, arg);
    semctl(semid, 1, SETVAL, arg);
    struct sembuf p = {1, -1, 0}, v = {0, 1, 0};
    char *addr = (char *)shmat(shmid, NULL, 0);
    if( addr < (char *)0 )
        err_sys("shmat error");

    while(1)
    {
        semop(semid, &p, 1);
        printf("server receive message from client:\n   %s\n", addr);
        int len = strlen(addr);
        int i;
        for(i = 0; i < len; i++)
            addr[i] = toupper(addr[i]);
        semop(semid, &v, 1);
    }
    shmdt(addr);
    semctl(semid, 0, IPC_RMID);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

