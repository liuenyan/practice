#include "sort.h"

static void swap(element_t elements[], int i, int j)
{
    element_t tmp = elements[i];
    elements[i] = elements[j];
    elements[j] = tmp;
}

static void max_heapify(element_t elements[], int element_size, int index)
{
    int largest = index;          /*最大值的下标*/
    int left_index = 2 * index + 1;     /*左节点*/
    int right_index = 2 * index + 2;    /*右节点*/

    if(left_index < element_size && elements[largest] < elements[left_index]) {
        largest = left_index;
    }
    if(right_index < element_size && elements[largest] < elements[right_index]) {
        largest = right_index;
    }

    if(largest != index) {
        swap(elements, index, largest);
        max_heapify(elements, element_size, largest);
    }
}

static void make_max_heap(element_t elements[], int element_size)
{
    for(int i = element_size/2-1; i >= 0; --i) {
        max_heapify(elements, element_size, i);
    }
}

void heap_sort(element_t elements[], int element_size)
{

    for(int i=element_size; i>=1; i--) {
        make_max_heap(elements, i);
        swap(elements, i-1, 0);
    }
}

