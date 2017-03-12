#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_list(struct list *lst)
{
    printf("head %p, tail %p, size %d\n", lst->head, lst->tail, lst->size);

    struct list_node *p;
    for(p=lst->head; p; p=p->next) {
        printf("%d%s", *((int *)p->data), list_is_tail(lst,p)? "" : "->");
    }
    printf("\n");
}

int main()
{
    struct list lst;
    int i;
    list_init(&lst, free);
    for (i=0; i<10; i++) {
        int *element = malloc(sizeof(int));
        *element = i;
        list_ins_next(&lst, lst.tail, element);
        print_list(&lst);
    }
    for(i=0; i<10; i++) {
        void *data;
        list_rem_next(&lst, NULL, &data);
        free(data);
        print_list(&lst);
    }
    list_destroy(&lst);
    return 0;
}
