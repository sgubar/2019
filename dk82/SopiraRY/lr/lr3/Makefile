CC=gcc
CFLAGS=-I -g -Wall
DEPS = sort.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sorttest: sorttest.o sort.o 
	$(CC) -o sorttest sorttest.o sort.o -lm
	rm *.txt *.o

