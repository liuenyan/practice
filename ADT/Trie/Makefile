.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: test_trie

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test_trie: test.o trie.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_trie
