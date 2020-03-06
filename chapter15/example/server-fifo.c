#include "apue.h"
#include <fcntl.h>
#include <ctype.h>

typedef struct tagmag{
    int client_pid;
    char my_data[512];
}MSG;

int main(void)
{
    int server_fifo_fd, client_fifo_fd;
    char client_fifo[256];
    MSG my_msg;
    char *pstr;
    memset(&my_msg, 0, sizeof(MSG));
    mkfifo("/tmp/SERVER_FIFO", 0777);
    server_fifo_fd = open("/tmp/SERVER_FIFO", O_RDWR);

    if(server_fifo_fd == -1)
        err_sys("open server fifo error");
    int iret;
    while((iret = read(server_fifo_fd, &my_msg, sizeof(MSG))) > 0){
        pstr = my_msg.my_data;
        printf("%s\n", my_msg.my_data);
        while(*pstr != '\0'){
            *pstr = toupper(*pstr);
            pstr++;
        }
        memset(client_fifo, 0, 256);
        sprintf(client_fifo, "/tmp/CLIENT_FIFO_%d", my_msg.client_pid);
        client_fifo_fd = open(client_fifo, O_WRONLY);
        if(client_fifo_fd == -1)
            err_sys("open client fifo error");
        write(client_fifo_fd, &my_msg, sizeof(MSG));
        printf("%s\n", my_msg.my_data);
        printf("OVER!\n");
        close(client_fifo_fd);
    }
    printf("iret = %d\n", iret);
    unlink("/tmp/SERVER_FIFO");
}

