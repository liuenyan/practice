#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

#define SZ 128

int compare(void* x, void* y)
{
    if (*(int*)x == *(int*)y) {
        return 0;
    } else if (*(int*)x < *(int*)y) {
        return -1;
    } else {
        return 1;
    }
}

int main(void)
{
    struct heap *heap = heap_new(compare, NULL);
    int arr[SZ];

    for(int i = 0; i<SZ; i++) {
        arr[i] = i;
        heap_insert(heap, &arr[i]);
    }
    void *data = NULL;
    for(int i = 0; i<SZ; i++) {
        heap_extract(heap, &data);
        printf("%d\n", *(int *)data);
    }
    heap_delete(heap);
    return 0;
}
