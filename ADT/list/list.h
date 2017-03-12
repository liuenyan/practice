#ifndef _LIST_H_
#define _LIST_H_ 1


/*一个单链表的实现*/

struct list_node {
    void *data;
    struct list_node *next;
};

struct list {
    struct list_node *head;     /*链表头*/
    struct list_node *tail;     /*链表结尾*/
    int size;                   /*当前元素的个数*/
    void (*destroy)(void *data);/*节点数据释放函数*/
};

void list_init(struct list *list, void (*destroy)(void *data));
void list_destroy(struct list *list);
int list_ins_next(struct list *list, struct list_node *node, const void *data);
int list_rem_next(struct list *list, struct list_node *node, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, node) ((list)->head == (node) ? 1 : 0)
#define list_is_tail(list, node) ((list)->tail == (node) ? 1 : 0)
#define list_data(node) ((node)->data)
#define list_next(node) ((node)->next)

#endif

