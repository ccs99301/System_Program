TARGET=shell

$(TARGET): shell.o error.o
	$(CC) -o $@ $^ 

shell.o: shell.c
error.o: error.c

clean:
	rm -f shell.o error.o $(TARGET)
