#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ll_stack.h"

/*初始化一个 ll_stack 结构体*/
struct ll_stack *ll_stack_init(void)
{
    struct ll_stack *plls = malloc(sizeof(struct ll_stack));
    if (plls == NULL) {
        fprintf(stderr, "%s %d: malloc\n", __FILE__, __LINE__);
        exit( EXIT_FAILURE );
    }
    plls->top = NULL;
    return plls;
}

/*释放一个 ll_stack 结构体*/
void ll_stack_destroy(struct ll_stack *plls)
{
    while(!ll_stack_empty(plls)){
        ll_stack_pop(plls);
    }
    free(plls);
}

/*向栈中压入一个元素，成功返回0, 失败返回-1*/
int ll_stack_push(struct ll_stack *plls, element_t *element)
{
    struct element_node *node = (struct element_node *)malloc(sizeof(struct element_node));
    if(node == NULL){
        fprintf(stderr, "%s %d: malloc\n", __FILE__, __LINE__);
        return -1;
    }
    memcpy(&node->value, element, sizeof(element_t));
    node->next = plls->top;
    plls->top = node;
    return 0;
}

/*获取栈顶元素，返回指向栈顶元素的指针*/
element_t *ll_stack_top(struct ll_stack *plls)
{
    return &plls->top->value;
}

/*弹出栈顶元素*/
void ll_stack_pop(struct ll_stack *plls)
{
    assert(!ll_stack_empty(plls));
    struct element_node *node = plls->top->next;
    free(plls->top);
    plls->top = node;
}

/*栈是否为空*/
int ll_stack_empty(struct ll_stack *plls)
{
    return plls->top == NULL;
}

/*栈是否为满，使用链表实现时，栈永远不会满*/
int ll_stack_full(struct ll_stack *plls)
{
    return 0;
}