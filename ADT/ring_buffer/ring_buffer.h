#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_ 1

struct ring_buffer {
    void **array;
    int array_size;
    int front;
    int rear;
    int size;
    void (*destroy)(void *data);
};

int rb_init(struct ring_buffer *rb, int capacity, void (*destroy)(void *data));
void rb_destroy(struct ring_buffer *rb);
int rb_insert(struct ring_buffer *rb, void *data);
int rb_remove(struct ring_buffer *rb, void **data);

#define rb_size(rb) ((rb)->size)
#define rb_is_empty(rb) ( ((rb)->rear + 1)%(rb)->array_size == (rb)->front )
#define rb_is_full(rb) ( ((rb)->rear + 2)%(rb)->array_size == (rb)->front )

#endif
