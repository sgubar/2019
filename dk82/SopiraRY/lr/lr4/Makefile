CC = gcc
CFLAGS = -g -Wall
DEPS = sort.h list.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

listuse: main.o sort.o list.o
	$(CC) -o listuse main.o sort.o list.o -lm
	rm *.o

