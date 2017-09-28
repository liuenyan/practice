
.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: test

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test: test.o bst.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test
