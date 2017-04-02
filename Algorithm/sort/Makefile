all:test_sort

CC=gcc
CFLAGS=-g3 -Wall -Wextra

test_sort: test.o insertion_sort.o heap_sort.o merge_sort.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o test_sort

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@
