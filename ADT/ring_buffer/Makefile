all: ring_buffer_test

CC=gcc
CFLAGS= -g -Wall -Wextra

ring_buffer_test: ring_buffer.o test.o
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) *.o ring_buffer_test

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<
