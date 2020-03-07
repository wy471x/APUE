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
    int fd = open(PATH, O_RDONLY);
    if(fd < 0)
        err_sys("open error");
    key_t key;
    int ret = read(fd, &key, sizeof(key));
    if(ret < 0)
        err_sys("read error");
    int semid = semget(key, 2, IPC_CREAT|0666);
    if(semid < 0)
        err_sys("semget error");
    int shmid = shmget(key, 1024 * 1024, IPC_CREAT|0666);
    if(shmid < 0)
        err_sys("shmget error");
    struct sembuf p = {0, -1, 0}, v = {1, 1, 0};
    char *addr = (char *)shmat(shmid, NULL, 0);
    if( addr < (char *)0 )
        err_sys("shmat error");

    while(1)
    {
        scanf("%s", addr);
        semop(semid, &v, 1);
        semop(semid, &p, 1);
        printf("client receive message from server:\n   %s\n", addr);
    }
    shmdt(addr);
    return 0;
}

