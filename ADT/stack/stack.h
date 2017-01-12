#ifndef _STACK_H_
#define _STACK_H_ 1

typedef int element_t;

struct stack {
    element_t *array;
    int size;
    int top_index;
};

struct stack *stack_init(int size);
void stack_destory(struct stack *p_stack);
void stack_push(struct stack *p_stack, element_t *element);
element_t *stack_top(struct stack *p_stack);
void stack_pop(struct stack *p_stack);
int stack_empty(struct stack *p_stack);
int stack_full(struct stack *p_stack);

#endif