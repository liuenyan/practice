#include <stdlib.h>
#include <string.h>
#include "sort.h"

/**
 * 合并左右两部分都已经排序的数组
 * elements 为待合并的数组
 * p 为左侧开始位置
 * q 为左侧结束位置
 * r 为右侧结束位置
 */
static void merge(element_t elements[], int p, int q, int r)
{
    int left_size = q - p + 1;
    int right_size = r - q;
    int total_size = left_size + right_size;
    
    int *left = malloc(left_size*sizeof(element_t));
    int *right = malloc(right_size*sizeof(element_t));

    memcpy(left, &elements[p], sizeof(element_t)*left_size);
    memcpy(right, &elements[q+1], sizeof(element_t)*right_size);
    
    int i = 0;
    int j = 0;
    int k;
    for(k = 0; i<left_size && j < right_size && k < total_size; ++k) {
        if(left[i] <= right[j]) {
            elements[k] = left[i];
            i++;
        }
        else {
            elements[k] = right[j];
            j++;
        }
    }

    if(i < left_size) {
        while (i<left_size) {
            elements[k++] = left[i++];
        }
    }

    else if (j < right_size) {
        while(j < right_size) {
            elements[k++] = right[j++];
        }
    }

    free(left);
    free(right);
}

void merge_sort(element_t elements[], int element_size)
{
    int p, q, r;
    
    if(element_size == 1)
        return;

    p = 0;
    r = element_size-1;
    q = (element_size-1)/2; 
    merge_sort(&elements[p], q-p+1);
    merge_sort(&elements[q+1], r-q);
    merge(elements, p, q, r); 
}

