CC=gcc
CFLAGS=-I -g -Wall
DEPS = matrix.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stuff: stuff.o matrix.o 
	$(CC) -o stuff stuff.o matrix.o
