all: ll_stack_test

CC=gcc
CFLAGS= -g -Wall -Wextra

ll_stack_test: ll_stack.o test.o
	$(CC) $(CFLAGS) $^ -o $@

%o:%c
	$(CC) -c $(CFLAGS) -o $@ $<
