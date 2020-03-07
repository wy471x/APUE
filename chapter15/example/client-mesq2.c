#include "apue.h"
#include <func.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#define PATH "/tmp/msgq"
#define BUFFER 255
struct mymsg{
    long mtype;
    char buffer[BUFFER+1];
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
    int serverMsgqId = msgget(serverKey, 0666|IPC_CREAT);
    struct mymsg msg;
    memset(&msg, 0, sizeof(struct mymsg));
    msg.mtype = 1;
    sprintf(msg.buffer,"%d", msgid);
    msgsnd(serverMsgqId, &msg, sizeof(msg.buffer), 0);
    msgrcv(msgid, &msg, sizeof(msg.buffer), 2, 0);
    fprintf(stdout, "%s", msg.buffer);

    /*  continue use private message queue to connect with server */
    while(1){
        msg.mtype = 1;
        fgets(msg.buffer, sizeof(msg.buffer), stdin);
        msg.buffer[strlen(msg.buffer)-1] = '\0';
        //printf("buf = %s, mtype = %ld, pid = %ld\n", msg.mtext.buffer, msg.mtype, msg.mtext.pid);
        msgsnd(msgid, &msg, sizeof(msg.buffer), 0);
        msgrcv(msgid, &msg, sizeof(msg.buffer), 2, 0);
        //printf("buf = %s, mtype = %ld\n", msg.mtext.buffer, msg.mtype);
        fprintf(stdout, "client receive message from server:\n   %s\n"
                , msg.buffer);
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

