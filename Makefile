CC = gcc
CFLAGS = -g
TARGET = chain

chain: simplechain.c
	$(CC) $? -o $@ $(CFLAGS)

clean:
	/bin/rm -f *.o $(TARGET)
