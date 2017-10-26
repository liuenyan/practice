.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: test_scapegoat_tree

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test_scapegoat_tree: test_scapegoat_tree.o ScapegoatTree.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_scapegoat_tree
