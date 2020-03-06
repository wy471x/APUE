#include "apue.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER 255
struct mdata{
    char buffer[BUFFER+1];
    long pid;
};

struct mymsg{
    long mtype;
    struct mdata mtext;
};

int main(int argc, char *argv[])
{
    int msgid = msgget((key_t)1234, 0666|IPC_CREAT);

    if(msgid == -1)
    {
        fprintf(stderr, "Create Message Error: %s\a\n", strerror(errno));
        exit(1);
    }

    struct mymsg msg;
    memset(&msg, 0, sizeof(struct mymsg));
    while(msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0)> 0){
        fprintf(stdout, "server receive message from client_%ld:\n   %s\n", msg.mtext.pid, 
                msg.mtext.buffer);
        fflush(stdout);
        int len = strlen(msg.mtext.buffer);
        int i;
        for(i = 0; i < len ; i++)
            msg.mtext.buffer[i] = toupper(msg.mtext.buffer[i]);
        msg.mtype = msg.mtext.pid;
        //printf("\nbuffer = %s , mtype = %ld, pid = %ld\n", msg.mtext.buffer, msg.mtype, msg.mtext.pid);
        msgsnd(msgid, &msg, sizeof(msg.mtext.buffer), 0);
    }
    exit(0);
}
