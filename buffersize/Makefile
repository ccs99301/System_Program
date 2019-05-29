all: error.o buffersize100.o buffersize4096.o buffersize8192 buffersize16384.o buffersize4096m.o
	gcc error.o buffersize100.o -o buffersize100
	gcc error.o buffersize4096.o -o buffersize4096
	gcc error.o buffersize8192.o -o buffersize8192
	gcc error.o buffersize16384.o -o buffersize16384
	gcc error.o buffersize4096m.o -o buffersize4096m

error: error.c
	gcc -c error.c

buffersize100: buffersize100.c
	gcc -c buffersize100.c

buffersize4096: buffersize4096.c
	gcc -c buffersize4096.c

buffersize8192: buffersize8192.c
	gcc -c buffersize8192.c

buffersize16384: buffersize16384.c
	gcc -c buffersize16384.c

buffersize4096m: buffersize4096m.c
	gcc -c buffersize4096m.c

clean:
	rm -f error.o buffersize100 buffersize4096 buffersize8192 buffersize16384 buffersize4096m buffersize*.o
