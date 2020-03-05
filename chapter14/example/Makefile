all : nonblockw deadlock mandatory rot13a rot13c2 mcopy2
CC=gcc
LIBS=-pthread
LRT=-lrt
nonblockw : nonblockw.c error.c setfl.c clrfl.c
	$(CC) -o $@ $^ $(LIBS) 

deadlock : deadlock.c error.c lockreg.c tellwait.c
	$(CC) -o $@ $^ $(LIBS)

mandatory : mandatory.c error.c lockreg.c tellwait.c setfl.c 
	$(CC) -o $@ $^ $(LIBS)

rot13a : rot13a.c error.c 
	$(CC) -o $@ $^

rot13c2 : rot13c2.c error.c
	$(CC) -o $@ $^ $(LRT)

mcopy2 : mcopy2.c error.c
	$(CC) -o $@ $^

clean:
	rm -rf nonblockw deadlock mandatory rot13a rot13c2 mcopy2 
	rm -rf *.o
