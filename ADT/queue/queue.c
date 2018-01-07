#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

/*初始化队列, 返回一个队列结构的指针*/
struct queue *queue_init(void)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    if (q == NULL){
        fprintf(stderr, "%s %d: malloc\n", __FILE__, __LINE__);
        exit( EXIT_FAILURE );
    }

    q->front = NULL;
    q->rear = NULL;

    return q;
}
/*销毁一个队列结构*/
void queue_destroy(struct queue *q)
{
    while(!queue_empty(q)){
        queue_dequeue(q);
    }
    free(q);
}

/*队列是否为空*/
int queue_empty(struct queue *q)
{
    return q->front == NULL && q->rear == NULL;
}

/*队列是否已满*/
int queue_full(struct queue *q)
{
    return 0;
}

/*入队操作, 在队列尾部放入一个元素*/
int queue_enqueue(struct queue *q, element_t *element)
{
    struct element_node *node = (struct element_node *)malloc(sizeof(struct element_node));
    if(node == NULL){
        fprintf(stderr, "%s %d: malloc\n", __FILE__, __LINE__);
        return -1;
    }

    memcpy(&node->value, element, sizeof(element_t));
    node->prev = NULL;
    node->next = q->rear;

    if(!queue_empty(q)) {
        q->rear->prev = node;
    }
    else{
        q->front = node;
    }
    q->rear = node;
    return 0;
}

/*取出队列头部的元素, 返回指向该元素的指针*/
element_t *queue_top(struct queue *q)
{
    assert(!queue_empty(q));
    return &q->front->value;
}

/*出队操作，丢弃队列头部数据*/
void queue_dequeue(struct queue *q)
{
    assert(!queue_empty(q));
    struct element_node *node = q->front;
    if(node->prev != NULL){
        /*断开与前一个节点的链接*/
        node->prev->next = NULL;
    }
    else{
        /*队列变为空*/
        q->rear = NULL;
    }
    q->front = node->prev;
    free(node);
}
