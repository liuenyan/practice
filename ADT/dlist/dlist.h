#ifndef _DLIST_H_
#define _DLIST_H_ 1

struct dlist_node {
    void *data;
    struct dlist_node *prev;
    struct dlist_node *next;
};

struct dlist {
    struct dlist_node *head;
    struct dlist_node *tail;
    int size;
    void (*destroy)(void *data);
};

void dlist_init(struct dlist *dlist, void (*destroy)(void *data));
void dlist_destroy(struct dlist *dlist);
int dlist_ins_prev(struct dlist *dlist, struct dlist_node *node, const void *data);
int dlist_ins_next(struct dlist *dlist, struct dlist_node *node, const void *data);
int dlist_remove(struct dlist *dlist, struct dlist_node *node, void **data);

#define dlist_size(dlist) ((dlist)->size)
#define dlist_head(dlist) ((dlist)->head)
#define dlist_tail(dlist) ((dlist)->tail)
#define dlist_is_head(dlist, node) ((dlist)->head == node ? 1 :0)
#define dlist_is_tail(dlist, node) ((dlist)->tail == node ? 1 :0)
#define dlist_prev(node) ((node)->prev)
#define dlist_next(node) ((node)->next)
#define dlist_data(node) ((node)->data)

#endif
