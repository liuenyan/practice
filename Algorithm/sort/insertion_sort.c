#include "sort.h"

void insertion_sort(element_t elements[], int element_size)
{
    for(int j = 1; j < element_size; j++) {
        element_t key = elements[j];
        int i;
        for (i = j-1; i >= 0 && elements[i] > key; i--) {
            elements[i+1] = elements[i];
        }
        elements[i+1] = key;
    }
}

