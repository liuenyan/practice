#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ring_buffer.h"

int rb_init(struct ring_buffer *rb, int capacity, void (*destroy)(void *data))
{
    assert(capacity > 1);
    rb->array = malloc((capacity+1)*sizeof(void *));
    if(!rb->array) {
        fprintf(stderr, "%s %d: malloc failed.\n", __FILE__, __LINE__);
        return -1;
    }

    rb->array_size = capacity+1;
    rb->front = 1;
    rb->rear = 0;
    rb->size = 0;
    rb->destroy = destroy;

    return 0;
}

void rb_destroy(struct ring_buffer *rb)
{
    void *data;

    while(!rb_is_empty(rb)) {
        rb_remove(rb, &data);
        if(rb->destroy) {
            rb->destroy(data);
        }
    }
    free(rb->array);
}

int rb_insert(struct ring_buffer *rb, void *data)
{
    if(rb_is_full(rb)) {
        return -1;
    }
    rb->rear = (rb->rear + 1) % rb->array_size;
    rb->array[rb->rear] = data;
    rb->size++;
    return 0;
}

int rb_remove(struct ring_buffer *rb, void **data)
{
    if(rb_is_empty(rb)) {
        return -1;
    }
    *data = rb->array[rb->front];
    rb->front = (rb->front + 1) % rb->array_size;
    rb->size--;
    return 0;
}

