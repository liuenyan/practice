#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

/*双链表初始化函数*/
void dlist_init(struct dlist *dlist, void (*destroy)(void *data))
{
    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->size = 0;
    dlist->destroy = destroy;
}

/*双链表销毁函数*/
void dlist_destroy(struct dlist *dlist)
{
    while(dlist_size(dlist) != 0) {
        void *data;
        dlist_remove(dlist, dlist_head(dlist), &data);
        if(dlist->destroy) {
            dlist->destroy(data);
        }
    }
}

/*在当前节点之前插入新节点*/
int dlist_ins_prev(struct dlist *dlist, struct dlist_node *node, const void *data)
{
    struct dlist_node *new_node = malloc(sizeof(struct dlist_node));
    if(!new_node) {
        fprintf(stderr, "%s %d: malloc failed\n", __FILE__, __LINE__);
        return -1;
    }
    new_node->data = (void *)data;

    /*插入位置非链表尾部*/
    if(node) {
        new_node->next = node;
        new_node->prev = node->prev;
        if(node->prev) {
            node->prev->next = new_node;
        } else {
            dlist->head = new_node;
        }
        node->prev = new_node;

    }
    /*插入位置位于链表尾部*/
    else {
        new_node->next = NULL;
        new_node->prev = dlist->tail;
        if (dlist_size(dlist)==0) {
            dlist->head = new_node;
        } else {
            dlist->tail->next = new_node;
        }
        dlist->tail = new_node;
    }
    dlist->size++;
    return 0;
}

/*在当前节点之后插入一个新节点*/
int dlist_ins_next(struct dlist *dlist, struct dlist_node *node, const void *data)
{
    struct dlist_node *new_node = malloc(sizeof(struct dlist_node));
    if(!new_node) {
        fprintf(stderr, "%s %d: malloc failed\n", __FILE__, __LINE__);
        return -1;
    }
    new_node->data = (void *)data;
    /*插入位置不在链表头部*/
    if(node) {
        new_node->prev = node;
        new_node->next = node->next;
        if(node->next) {
            node->next->prev = new_node;
        } else {
            dlist->tail = new_node;
        }
        node->next = new_node;
    }
    /*插入位置在链表头部*/
    else {
        new_node->next = dlist->head;
        new_node->prev = NULL;
        if (dlist_size(dlist)==0) {
            dlist->tail = new_node;

        } else {
            dlist->head->prev = new_node;
        }
        dlist->head = new_node;
    }
    dlist->size++;
    return 0;
}

/*删除一个节点*/
int dlist_remove(struct dlist *dlist, struct dlist_node *node, void **data)
{
    *data = node->data;
    /*删除位置不在链表头部*/
    if(node->prev) {
        node->prev->next = node->next;
        if(node->next) {
            node->next->prev = node->prev;
        } else {
            dlist->tail = NULL;
        }
    }
    /*删除位置在链表头部*/
    else {
        dlist->head = node->next;
        if(node->next) {
            node->next->prev = NULL;
        } else {
            dlist->tail = NULL;
        }
    }
    free(node);
    dlist->size--;
    return 0;
}
