.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: test_treap

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test_treap: test_treap.o treap.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_treap
