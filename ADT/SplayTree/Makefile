.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: test_splay_tree

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test_splay_tree: test_splay_tree.o SplayTree.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_splay_tree
