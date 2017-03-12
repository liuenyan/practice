all: stack_test

CC=gcc
CFLAGS= -g -Wall -Wextra

stack_test: stack.o test.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o stack_test

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<
