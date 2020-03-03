all : nonblockw deadlock mandatory
CC=gcc
LIBS=-pthread
nonblockw : nonblockw.o error.o setfl.o clrfl.o
	$(CC) -o $@ $^ $(LIBS) 

deadlock : deadlock.o error.o lockreg.o tellwait.o
	$(CC) -o $@ $^ $(LIBS)

mandatory : mandatory.o error.o lockreg.o tellwait.o setfl.o 
	$(CC) -o $@ $^ $(LIBS)

nonblockw.o : apue.h
deadlock.o : apue.h
mandatory.o :apue.h
error.o	: apue.h
setfl.o : apue.h
clrfl.o : apue.h
tellwait.o : apue.h
lockreg.o :apue.h

clean:
	rm -rf nonblockw deadlock mandatory 
	rm -rf *.o
