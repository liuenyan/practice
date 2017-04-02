#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define array_size(array) (sizeof(array)/sizeof(array[0]))

typedef void (*sort_func_t)(element_t elements[], int element_size);

void print_array(element_t a[], int size)
{
    for(int i=0; i<size; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

int test_sort(sort_func_t sort_function)
{
    element_t a[21];
    srand(time(NULL));

    for(int i=0; i<21; i++) {
        a[i] = rand() % 1000;
    }

    print_array(a, array_size(a));
    sort_function(a, array_size(a));
    print_array(a, array_size(a));
    return 0;
}

int main()
{
    printf("test insertion_sort:\n");
    test_sort(insertion_sort);

    printf("test heap_sort:\n");
    test_sort(heap_sort);

    printf("test merge_sort:\n");
    test_sort(merge_sort);
    return 0;
}
