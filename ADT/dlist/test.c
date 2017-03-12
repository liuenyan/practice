#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

void print_dlist(struct dlist *dlist)
{
    struct dlist_node *p;
    printf("dlist head %p, tail %p, size %d\n", dlist->head, dlist->tail, dlist->size);
    for(p=dlist->head; p; p=p->next) {
        printf("%d%s", *(int *)p->data, dlist_is_tail(dlist, p)?"":"->");
    }
    printf("\n");
}

int main()
{
    struct dlist dlist;
    dlist_init(&dlist, free);
    for(int i=0; i<10; i++) {
        int *data = malloc(sizeof(int));
        *data = i;
        dlist_ins_next(&dlist, dlist_tail(&dlist), data);
    }
    print_dlist(&dlist);
    struct dlist_node *p;
    for(p=dlist.head; p!=NULL && *(int *)p->data != 5; p=p->next)
        ;
    int *data1 = malloc(sizeof(int));
    *data1 = 100;
    dlist_ins_next(&dlist, p, data1);
    print_dlist(&dlist);
    int *data2 = malloc(sizeof(int));
    *data2 = 200;
    dlist_ins_prev(&dlist, p, data2);
    print_dlist(&dlist);
    dlist_destroy(&dlist);
    print_dlist(&dlist);
    return 0;
}
