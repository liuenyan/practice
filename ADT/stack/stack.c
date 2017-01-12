#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

/*初始化堆栈, size 为堆栈的大小， 返回堆栈结构体的指针*/
struct stack *stack_init(int size)
{
    assert(size > 0);
    struct stack *ps = (struct stack *)malloc(sizeof(struct stack));
    if(ps == NULL){
        fprintf(stderr, "%s %d: malloc\n", __FILE__, __LINE__);
        exit( EXIT_FAILURE );
    }
    ps->array = (element_t *)malloc(size * sizeof(element_t));
    if (ps->array == NULL){
        fprintf(stderr, "%s %d: malloc\n", __FILE__, __LINE__);
        exit( EXIT_FAILURE );
    }
    ps->top_index = -1;
    ps->size = size;
    return ps;
}

/*销毁一个堆栈结构体*/
void stack_destory(struct stack *p_stack)
{
    assert(p_stack != NULL);
    free(p_stack->array);
    free(p_stack);
}

/*判断堆栈是否为空*/
int stack_empty(struct stack *p_stack)
{
    assert(p_stack != NULL);
    return p_stack->top_index == -1;
}

/*判断堆栈是否已满*/
int stack_full(struct stack *p_stack)
{
    assert(p_stack != NULL);
    return p_stack->top_index == p_stack->size-1;
}

/*获得当前栈顶元素， 返回一个指向栈顶元素的指针*/
element_t *stack_top(struct stack *p_stack)
{
    return &p_stack->array[p_stack->top_index];
}

/*从堆栈弹出一个元素*/
void stack_pop(struct stack *p_stack)
{
    assert(!stack_empty(p_stack));
    p_stack->top_index--;
}

/*向堆栈中压入一个元素，element 为压入的元素的指针*/
void stack_push(struct stack *p_stack, element_t *element)
{
    assert(!stack_full(p_stack));
    memcpy(&p_stack->array[++p_stack->top_index], element, sizeof(element_t));
}
