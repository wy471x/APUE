EXE=findsvc ruptime ruptimed ruptime-dg ruptimed-dg
CC=gcc
all : $(EXE)
findsvc : findsvc.c error.c
	$(CC) -o $@ $^
ruptime : ruptime.c error.c clconn2.c 
	$(CC) -o $@ $^
ruptimed : ruptimed.c error.c initsvc1.c init.c setfd.c
	$(CC) -o $@ $^
ruptime-dg : ruptime-dg.c error.c clconn2.c
	$(CC) -o $@ $^
ruptimed-dg : ruptimed-dg.c error.c initsvc1.c init.c setfd.c
	$(CC) -o $@ $^

clean:
	rm -rf $(EXE)
