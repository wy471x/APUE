CFLAGS:=-Wall
CC:=gcc
LIBS:=-lpthread
ELF:=reread
SRCS:=reread.c single.c  error.c lockfile.c init.c
OBJS:=$(patsubst %.c,%.o,$(SRCS))
$(ELF):$(OBJS)
	$(CC) -o $(ELF) $(OBJS) $(CFLAGS) $(LIBS)

init.o: init.c apue.h
	$(CC) -c init.c
single.o: single.c
	$(CC) -c single.c
lockfile.o: lockfile.c
	$(CC) -c lockfile.c
reread.o: reread.c apue.h
	$(CC) -c reread.c
error.o: error.c apue.h
	$(CC) -c error.c

clean:
	rm -rf $(ELF)
	rm -rf $(OBJS)
