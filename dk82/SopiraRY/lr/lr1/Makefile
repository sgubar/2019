CC=gcc
CFLAGS=-I -g -Wall
DEPS = function.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

formulae: formulae.o function.o 
	$(CC) -o formulae formulae.o function.o
