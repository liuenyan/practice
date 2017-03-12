all:test_list

CC=gcc
CFLAGS=-g3 -Wall -Wextra

test_list: test.o list.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o test_list

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@
