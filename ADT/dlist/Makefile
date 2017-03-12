all:test_dlist

CC=gcc
CFLAGS=-g3 -Wall -Wextra

test_dlist: test.o dlist.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o test_dlist

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@
