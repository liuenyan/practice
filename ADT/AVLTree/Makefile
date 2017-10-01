.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: test_avl

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test_avl: test.o AVLTree.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_avl
