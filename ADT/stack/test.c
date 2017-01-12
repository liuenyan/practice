#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define PRINT_STACK_STATUS(ps) \
    printf("empty: %d full: %d\n", stack_empty(ps), stack_full(ps))

int main()
{
    int i;
    struct stack *ps = stack_init(10);
    PRINT_STACK_STATUS(ps);
    
    for(i=0; i<10; i++){
        stack_push(ps, &i);
        PRINT_STACK_STATUS(ps);
    }
    
    for(i=0; i<10; i++){
        printf("%d\n", *stack_top(ps));
        stack_pop(ps);
        PRINT_STACK_STATUS(ps);
    }
    stack_destory(ps);
    return 0;
}
