#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element_t;

void print_array(element_t a[], int size)
{
    for(int i=0; i<size; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

int insertion_sort(element_t elements[], int element_size)
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

int main()
{
    element_t a[21];
    srand(time(NULL));

    for(int i=0; i<21; i++) {
        a[i] = rand() % 1000;
    }

    print_array(a, sizeof(a)/sizeof(element_t));
    insertion_sort(a, sizeof(a)/sizeof(element_t));
    print_array(a, sizeof(a)/sizeof(element_t));
    return 0;
}

