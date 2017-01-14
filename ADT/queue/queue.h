#ifndef _QUEUE_H_
#define _QUEUE_H_ 1

typedef int element_t;

/*双向链表节点*/
struct element_node {
    element_t value;
    struct element_node *prev; /*前一个节点*/
    struct element_node *next; /*后一个节点*/
};

struct queue {
    struct element_node *front; /*队列头指针*/
    struct element_node *rear;  /*队列尾指针*/
};

struct queue *queue_init(void);
void queue_destroy(struct queue *q);
int queue_empty(struct queue *q);
int queue_full(struct queue *q);
int queue_enqueue(struct queue *q, element_t *element);
element_t *queue_top(struct queue *q);
void queue_dequeue(struct queue *q);

#endif