TARGET = chain
OBJECT = simplechain.o

%.o: %.c
	$(CC) -c -std=gnu99 $<

chain: $(OBJECT)
	gcc -o chain ${OBJECT}

clean:
	/bin/rm -f *.o $(TARGET)