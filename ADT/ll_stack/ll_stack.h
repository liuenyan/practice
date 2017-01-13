#ifndef _LL_STACK_H_
#define _LL_STACK_H_ 1

/*使用单链表实现的栈*/

typedef int element_t;

/*链表的节点*/
struct element_node {
    element_t value;
    struct element_node *next;
};

/*栈的结构体*/
struct ll_stack {
    struct element_node *top;
};

struct ll_stack *ll_stack_init(void);
void ll_stack_destroy(struct ll_stack *plls);
int ll_stack_push(struct ll_stack *plls, element_t *element);
element_t *ll_stack_top(struct ll_stack *plls);
void ll_stack_pop(struct ll_stack *plls);
int ll_stack_empty(struct ll_stack *plls);
int ll_stack_full(struct ll_stack *plls);

#endif