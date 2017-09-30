#ifndef _SORT_H_
#define _SORT_H_

typedef int element_t;

void insertion_sort(element_t elements[], int element_size);
void heap_sort(element_t elements[], int element_size);
void merge_sort(element_t elements[], int element_size);
void quick_sort(element_t elements[], int element_size);

#endif
