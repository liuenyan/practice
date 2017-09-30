#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

static inline void swap(element_t elements[], int i, int j)
{
    element_t tmp = elements[i];
    elements[i] = elements[j];
    elements[j] = tmp;
}

/**
 * 分区函数
 */
static int partition(element_t elements[], int p, int r)
{
    /* 随机选取一个主元 */
    int idx = rand() % (r - p + 1) + p;
    swap(elements, idx, r);

    int i = p - 1;
    element_t pivot = elements[r];

    for(int j = p; j < r; j++) {
        if (elements[j] <= pivot) {
            i++;
            swap(elements, i, j);
        }
    }
    swap(elements, i+1, r);
    return i+1;
}

static void qksort (element_t elements[], int p, int r)
{
    if (r > p) {
        /*当元素个数大于1时，递归进行调用*/
        int q = partition(elements, p, r);
        qksort(elements, p, q-1);
        qksort(elements, q+1, r);
    }
}

void quick_sort(element_t elements[], int elements_size)
{
    qksort(elements, 0, elements_size - 1);
}
