#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

struct heap {
    int size;
    int capacity;
    void **tree;
    int (*compare)(void *, void *);
    void (*destroy)(void *);
};
struct heap* heap_new(int (*compare)(void*, void*), void (*destroy)(void*));
void heap_delete(struct heap* heap);
int heap_insert(struct heap* heap, void* data);
int heap_extract(struct heap* heap, void** data);

#define heap_size(heap) ((heap)->size)

#endif
