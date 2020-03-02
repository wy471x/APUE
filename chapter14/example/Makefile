TARGET:=nonblockw
OBJS:=error.o nonblockw.o setfl.o clrfl.o
CC:=gcc
LIBS=-pthread
$(TARGET):$(OBJS)
	$(CC) -o $@ $^ $(LIBS)

errno.o:error.c apue.h
	$(CC) -c $< -o $@
nonblockw.o:nonblockw.c apue.h
	$(CC) -c $< -o $@
setfl.o:setfl.c apue.h
	$(CC) -c $< -o $@
clrfl.o:clrfl.c apue.h
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(TARGET)
