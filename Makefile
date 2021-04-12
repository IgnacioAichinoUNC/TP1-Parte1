CC=gcc
CFLAGS=-I.

execute: calc.o
	$(CC) -o execute calc.o
clean:
	rm *.o execute

