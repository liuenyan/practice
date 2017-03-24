#include <stdio.h>
#include <stdlib.h>
#include "ring_buffer.h"

void print_rb(struct ring_buffer *rb)
{
    printf("front %d rear %d size %d\n", rb->front, rb->rear, rb->size);
    for(int i=rb->front;
            i != (rb->rear+1)%rb->array_size;
            i = (i+1)%rb->array_size) {
        printf("%d%c", *(int *)rb->array[i], i==rb->rear ? '\n' : ' ');
    }
}

int main()
{
    struct ring_buffer rb;

    rb_init(&rb, 10, free);

    for(int i=0; !rb_is_full(&rb); ++i) {
        int *data = malloc(sizeof(int));
        *data = i;
        rb_insert(&rb, data);
    }
    print_rb(&rb);

    for(int i=0; i<9; ++i) {
        void *data;
        rb_remove(&rb, &data);
        free(data);
    }
    print_rb(&rb);

    for(int i=0; !rb_is_full(&rb); ++i) {
        int *data = malloc(sizeof(int));
        *data = i;
        rb_insert(&rb, data);
    }
    print_rb(&rb);

    rb_destroy(&rb);

    return 0;
}
