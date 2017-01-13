#include <stdio.h>
#include <stdlib.h>
#include "ll_stack.h"

int main()
{
    int i;
    struct ll_stack *plls = ll_stack_init();

    for(i=0; i<20; i++){
        ll_stack_push(plls, &i);
        printf("top %d\n", *ll_stack_top(plls));
    }

    for(i=0; i<20; i++){
        printf("%d\n", *ll_stack_top(plls));
        ll_stack_pop(plls);
        printf("empty %d\n", ll_stack_empty(plls));
    }

    ll_stack_destroy(plls);
    return 0;
}