EXE=settty csize test-ctermid t_ttyname t_getpass t_raw winch
CC=gcc
all : $(EXE)

settty : settty.c error.c
	$(CC) -o $@ $^ 
csize : csize.c error.c
	$(CC) -o $@ $^
ctermid : ctermid.c
	$(CC) -o $@ $^
t_ttyname : t_ttyname.c ttyname.c
	$(CC) -o $@ $^
t_getpass :t_getpass.c error.c getpass.c
	$(CC) -o $@ $^
t_raw : t_raw.c error.c ttymodes.c
	$(CC) -o $@ $^
winch : winch.c error.c isatty.c 
	$(CC) -o $@ $^

clean :
	rm -f $(EXE)
