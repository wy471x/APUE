#include "apue.h"
#include <func.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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
    int msgid = msgget(IPC_PRIVATE, 0666|IPC_CREAT);
    if(msgid == -1){
        fprintf(stderr, "Create Message Error: %s\a\n", strerror(errno));
        exit(1);
    }
    key_t serverKey;
    int fd;
    if((fd = open(PATH, O_RDONLY)) < 0)
        err_sys("open error");
    int n;
    if((n = read(fd, &serverKey, sizeof(serverKey))) < 0)
        err_sys("read error");

    /* first request to server */
    int servermsgid = msgget(serverKey, 0666|IPC_CREAT);
    struct mymsg msg;
    memset(&msg, 0, sizeof(struct mymsg));
    msg.mtype = 1;
    msg.mtext.msgqid = msgid;
    msgid = servermsgid;
    /*  continue use private message queue to connect with server */
    while(1){
        fgets(msg.mtext.buffer, sizeof(msg.mtext.buffer), stdin);
        msg.mtext.buffer[strlen(msg.mtext.buffer)-1] = '\0';
        //printf("buf = %s, mtype = %ld, pid = %ld\n", msg.mtext.buffer, msg.mtype, msg.mtext.pid);
        msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
        msgrcv(msgid, &msg, sizeof(msg.mtext), 2, 0);
        //printf("buf = %s, mtype = %ld\n", msg.mtext.buffer, msg.mtype);
        fprintf(stdout, "client receive message from server:\n   %s\n",msg.mtext.buffer);
        msg.mtype = 1;
        msgid = msg.mtext.msgqid; 
    }
    return 0;
}

