EXE=pollmsg sendmsg bindunix
CC=gcc
LIBS=-pthread
all : $(EXE)
pollmsg : pollmsg.c error.c
	$(CC) -o $@ $^ $(LIBS)
sendmsg :sendmsg.c error.c
	$(CC) -o $@ $^
bindunix :bindunix.c error.c
	$(CC) -o $@ $^

clean : 
	rm -f $(EXE)
