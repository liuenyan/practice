#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*单链表初始化函数*/
void list_init(struct list *list, void (*destroy)(void *data))
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->destroy = destroy;
}

/*
 * 单链表销毁函数, 销毁单链表中的所有节点. 如果 list->destroy 函数不为空，
 * 该函数将调用 list->destroy 函数释放每个节点的data指针所引用的内存.
 * 调用该函数后除非再次调用list_init, 否则任何其他操作都不允许
 */
void list_destroy(struct list *list)
{
    void *data;
    while(list_size(list)!=0) {
        list_rem_next(list, NULL, &data);
        if(list->destroy) list->destroy(data);
    }
    memset(list, 0, sizeof(struct list));
}

/*
 * 在当前节点后插入一个新节点, node==NULL 代表插入位置在链表头.
 * 当 data 在链表中时，所引用的内存空间应当保持合法.
 * 管理 data 所引用的空间是调用者的责任
 */
int list_ins_next(struct list *list, struct list_node *node, const void *data)
{
    /*创建一个新节点*/
    struct list_node *new_node = malloc(sizeof(struct list_node));
    if(!new_node) {
        fprintf(stderr, "%s %d: malloc failed.\n",__FILE__, __LINE__);
        return -1;
    }
    new_node->data = (void *) data;

    /*插入位置不是链表头*/
    if(node) {
        new_node->next = list_next(node);
        /*插入的位置位于链表尾部*/
        if(!node->next) list->tail = new_node;

        node->next = new_node;
    }
    /*插入位置是链表头*/
    else {
        new_node->next = list_head(list);
        /*链表原来为空*/
        if(!list_head(list)) list->tail = new_node;
        
        list->head = new_node;
    }
    list->size++;
    return 0;
}

/* 
 * 删除当前节点后的节点, 成功返回0, 失败返回-1.
 * 当 node==NULL 时, 删除的位置在链表头.
 * 被释放的节点的数据域指针保存在 data 中,管理数据域的内存空间是调用者的责任.
 */
int list_rem_next(struct list *list, struct list_node *node, void **data)
{
    /*获取实际要删除的节点*/
    struct list_node *next_node = node ? list_next(node): list_head(list);
    if(!next_node) return -1;
    
    /*执行删除操作*/
    struct list_node *tmp = list_next(next_node);
    *data = next_node->data;
    free(next_node);
    list->size--;

    /*删除的节点位于链表尾部*/
    if(!tmp) {
        list->tail = node;
    }
    /*删除的节点不在链表头*/
    if(node) {
        node->next = tmp;
    }
    /*删除的节点位于链表头*/
    else {
        list->head = tmp;
    }
    return 0;
}
