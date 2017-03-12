all: queue_test

CC=gcc
CFLAGS= -g -Wall -Wextra

queue_test: queue.o test.o
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) *.o queue_test

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<
