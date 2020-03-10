EXE=pipe1 pipe1-test pipe2 popen2 popen1 myuclc add2 pipe4 add2stdio write read server-fifo client-fifo server-mesq client-mesq server-mesq2 client-mesq2 server-shm-sem client-shm-sem
CC=gcc
all : $(EXE)
pipe1 : pipe1.c error.c
	$(CC) -o $@ $^
pipe1-test : pipe1-test.c error.c
	$(CC) -o $@ $^
pipe2 : pipe2.c error.c
	$(CC) -o $@ $^
popen2 : popen2.c error.c
	$(CC) -o $@ $^
popen1 : popen1.c error.c
	$(CC) -o $@ $^
myuclc : myuclc.c error.c
	$(CC) -o $@ $^
add2 : add2.c error.c
	$(CC) -o $@ $^
pipe4 : pipe4.c error.c
	$(CC) -o $@ $^
add2stdio : add2stdio.c error.c
	$(CC) -o $@ $^
write : write.c error.c
	$(CC) -o $@ $^
read : read.c error.c
	$(CC) -o $@ $^
server-fifo : server-fifo.c error.c
	$(CC) -o $@ $^
client-fifo : client-fifo.c error.c
	$(CC) -o $@ $^
server-mesq : server-mesq.c error.c
	$(CC) -o $@ $^
client-mesq : client-mesq.c error.c
	$(CC) -o $@ $^
server-mesq2 : server-mesq2.c error.c
	$(CC) -o $@ $^
client-mesq2 : client-mesq2.c error.c
	$(CC) -o $@ $^
server-shm-sem : server-shm-sem.c error.c
	$(CC) -o $@ $^
client-shm-sem : client-shm-sem.c error.c
	$(CC) -o $@ $^

clean :
	rm -rf *.o
	rm -rf $(EXE)
