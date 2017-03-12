all: ll_stack_test

CC=gcc
CFLAGS= -g -Wall -Wextra

ll_stack_test: ll_stack.o test.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o ll_stack_test

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<
