#include <func.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFFER 255
struct mdata{
    char buffer[BUFFER+1];
    long pid;
};
struct mymsg{
    long mtype;
    struct mdata mtext;
};

int main(void)
{
    int msgid = msgget((key_t)1234, 0666|IPC_CREAT);
    if(msgid == -1){
        fprintf(stderr, "Create Message Error: %s\a\n", strerror(errno));
        exit(1);
    }

    struct mymsg msg;
    memset(&msg, 0, sizeof(struct mymsg));
    msg.mtype = 1;
    msg.mtext.pid = getpid();
    long pid = getpid();
    while(1){
        fgets(msg.mtext.buffer, sizeof(msg.mtext.buffer), stdin);
        msg.mtext.buffer[strlen(msg.mtext.buffer)-1] = '\0';
        //printf("buf = %s, mtype = %ld, pid = %ld\n", msg.mtext.buffer, msg.mtype, msg.mtext.pid);
        msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
        memset(&msg, 0, sizeof(struct mymsg));
        msgrcv(msgid, &msg, sizeof(msg.mtext), pid, 0);
        //printf("buf = %s, mtype = %ld\n", msg.mtext.buffer, msg.mtype);
        fprintf(stdout, "client receive message from server:\n   %s\n",msg.mtext.buffer);
        memset(&msg, 0, sizeof(struct mymsg));
        msg.mtype = 1;
        msg.mtext.pid = getpid();
    }
    return 0;
}

