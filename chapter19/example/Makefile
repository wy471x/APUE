EXE=pty add2 pipe4
CC=gcc
all : $(EXE)

pty : main.c error.c driver.c loop.c ttymodes.c signalintr.c writen.c spipe.c ptyfork.c ptyopen.c 
	$(CC) -o $@ $^
add2 : add2.c error.c
	$(CC) -o $@ $^
pipe4 : pipe4.c error.c
	$(CC) -o $@ $^

clean :
	rm -f $(EXE)
