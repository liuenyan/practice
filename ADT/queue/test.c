#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    int i;
    struct queue *q = queue_init();
    for(i=0; i<20; i++){
        queue_enqueue(q, &i);
    }
    for(i=0;i<20;i++){
        printf("%d\n", *queue_top(q));
        queue_dequeue(q);
    }
    printf("empty: %d\n", queue_empty(q));
    queue_destroy(q);
    return 0; 
}