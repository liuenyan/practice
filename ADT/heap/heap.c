#include "heap.h"
#include <stdlib.h>

#define PARENT(i) ((i-1)/2)
#define LEFT(i) (2*(i)+ 1)
#define RIGHT(i) (2*(i)+ 2)

struct heap* heap_new(int (*compare)(void*, void*), void (*destroy)(void*))
{
    struct heap* heap = malloc(sizeof(*heap));
    if (!heap) {
        return NULL;
    }
    heap->capacity = 16;
    heap->tree = calloc(heap->capacity, sizeof(void*));
    if (!heap->tree) {
        free(heap);
        return NULL;
    }
    heap->compare = compare;
    heap->destroy = destroy;
    heap->size = 0;
    return heap;
}

void heap_delete(struct heap* heap)
{
    if (heap->destroy != NULL) {
        for (int i = 0; i < heap->size; i++) {
            heap->destroy(heap->tree[i]);
        }
    }
    free(heap->tree);
    free(heap);
}

int heap_insert(struct heap* heap, void* data)
{
    if (heap->size == heap->capacity) {
        void* tmp = realloc(heap->tree, 2 * sizeof(void*) * heap->capacity);
        if (tmp == NULL) {
            return -1;
        } else {
            heap->tree = tmp;
            heap->capacity *= 2;
        }
    }
    heap->tree[heap->size] = data;
    int ipos = heap->size;
    int ppos = PARENT(ipos);
    while (ipos > 0 && heap->compare(heap->tree[ppos], heap->tree[ipos]) < 0) {
        void* tmp = heap->tree[ppos];
        heap->tree[ppos] = heap->tree[ipos];
        heap->tree[ipos] = tmp;
        ipos = ppos;
        ppos = PARENT(ipos);
    }
    heap->size++;
    return 0;
}
int heap_extract(struct heap* heap, void** data)
{
    if (heap->size == 0) {
        *data = NULL;
        return -1;
    }
    *data = heap->tree[0];
    heap->size--;
    heap->tree[0] = heap->tree[heap->size];
    int ipos = 0;
    int lpos, rpos, mpos;
    while (1) {
        lpos = LEFT(ipos);
        rpos = RIGHT(ipos);
        mpos = ipos;

        if (lpos < heap->size
            && heap->compare(heap->tree[lpos], heap->tree[mpos]) > 0) {
            mpos = lpos;
        }
        if (rpos < heap->size
            && heap->compare(heap->tree[rpos], heap->tree[mpos]) > 0) {
            mpos = rpos;
        }
        if (mpos == ipos) {
            break;
        }
        void* tmp = heap->tree[ipos];
        heap->tree[ipos] = heap->tree[mpos];
        heap->tree[mpos] = tmp;
        ipos = mpos;
    }
    return 0;
}
