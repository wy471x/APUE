#include "apue.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#define PATH "/tmp/msgq"
#define BUFFER 255
struct mdata{
    char buffer[BUFFER+1];
    long msgqid;
};

struct mymsg{
    long mtype;
    struct mdata mtext;
};

int main(void)
{
    key_t key = ftok(PATH, 1);

    int fd;
    if((fd = open(PATH, O_WRONLY)) < 0)
        err_sys("open error");
    write(fd, &key, sizeof(key));

    int msgid = msgget(key, 0666|IPC_CREAT);
    if(msgid == -1)
    {
        fprintf(stderr, "Create Message Error: %s\a\n", strerror(errno));
        exit(1);
    }

    struct mymsg msg;
    int commonmsgid = msgid;
    memset(&msg, 0, sizeof(struct mymsg));
    while(msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0) > 0){
        if(msg.mtext.msgqid == commonmsgid)
    
        fprintf(stdout, "server receive message from clientmsgid_%ld:\n   %s\n",
                msg.mtext.msgqid, msg.mtext.buffer);
        fflush(stdout);
        int len = strlen(msg.mtext.buffer);
        int i;
        for(i = 0; i < len ; i++)
            msg.mtext.buffer[i] = toupper(msg.mtext.buffer[i]);
        msg.mtype = 2;
        msgid = msg.mtext.msgqid;
        msgsnd(msgid, &msg, sizeof(msg.mtext.buffer), 0);
    }
    exit(0);
}
