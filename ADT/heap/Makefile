.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: test_heap

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test_heap: test_heap.o heap.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_heap
