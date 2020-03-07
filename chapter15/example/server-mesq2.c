#include "apue.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#define PATH "/tmp/msgq"
#define BUFFER 255

struct mymsg{
    long mtype;
    char buffer[BUFFER+1];
};

void child_make(int msgqid)
{
    int pid;
    struct mymsg msg;
    memset(&msg, 0, sizeof(msg));
    if((pid = fork()) == 0){
        while(1)
        {
            msgrcv(msgqid, &msg, sizeof(msg.buffer), 1, 0);
            fprintf(stdout, "server receive message from client:\n   %s\n", 
                    msg.buffer);
            msg.mtype = 2;
            int len = strlen(msg.buffer);
            int i;
            for(i = 0; i < len; i++)
                msg.buffer[i] = toupper(msg.buffer[i]);
            msgsnd(msgqid, &msg, sizeof(msg.buffer), 0);
        }
    }
}

int main(void)
{
    key_t key = ftok(PATH, 1);

    int fd;
    if((fd = open(PATH, O_WRONLY)) < 0)
        err_sys("open error");
    write(fd, &key, sizeof(key));

    int commonMsgqId = msgget(key, 0666|IPC_CREAT);
    if(commonMsgqId == -1)
    {
        fprintf(stderr, "Create Message Error: %s\a\n", strerror(errno));
        exit(1);
    }

    struct mymsg msg;
    memset(&msg, 0, sizeof(struct mymsg));
    msg.mtype = 2;
    while(1)
    {
        /* main process listen to common message queue  */
        msgrcv(commonMsgqId, &msg, sizeof(msg.buffer), 1, 0);
        int msgqId = atoi(msg.buffer);
        msg.mtype = 2;
        strcpy(msg.buffer, "connect to server...\n");
        msgsnd(msgqId, &msg, sizeof(msg.buffer), 0);
        /* child process handle request from client  */
        child_make(msgqId);
    }
    msgctl(commonMsgqId, IPC_RMID, NULL);
    exit(0);
}
