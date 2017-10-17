#include "treap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Treap* Treap_new(int (*compare)(void*, void*))
{
    struct Treap* tree = malloc(sizeof(struct Treap));
    if (!tree)
        return NULL;

    tree->root = NULL;
    tree->compare = compare;
    tree->seed = time(NULL);
    return tree;
}

struct TreapNode* TreapNode_new(struct Treap* tree, void* data)
{
    struct TreapNode* node = malloc(sizeof(struct TreapNode));
    if (!node)
        return NULL;
    node->parent = node->left = node->right = NULL;
    node->data = data;
    node->priority = rand_r(&tree->seed);
    return node;
}

/**
 *     x           y
 *    / \         / \
 *   s   y   ->  x   z
 *      / \     / \
 *     w   z   s   w
 */
static void left_rotate(struct Treap* tree, struct TreapNode* x)
{
    struct TreapNode* y = x->right;
    x->right = y->left;
    if (y->left) {
        y->left->parent = x;
    }

    y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->left) {
            x->parent->left = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            assert(0);
        }
    } else {
        tree->root = y;
    }

    y->left = x;
    x->parent = y;
}

/*
 *     x           y
 *    / \         / \
 *   y   s   ->  w   x
 *  / \             / \
 * w   z           z   s
 */
static void right_rotate(struct Treap* tree, struct TreapNode* x)
{
    struct TreapNode* y = x->left;
    x->left = y->right;
    if (y->right) {
        y->right->parent = x;
    }

    y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->left) {
            x->parent->left = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            assert(0);
        }
    } else {
        tree->root = y;
    }
    y->right = x;
    x->parent = y;
}

void Treap_insert(struct Treap* tree, struct TreapNode* node)
{
    struct TreapNode* p = tree->root;
    struct TreapNode* prev = NULL;

    /*插入节点*/
    int r = 0;
    while (p) {
        prev = p;
        r = tree->compare(node->data, p->data);
        if (r < 0) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    if (!prev) {
        tree->root = node;
        return;
    }

    node->parent = prev;
    if (r < 0) {
        prev->left = node;
    } else {
        prev->right = node;
    }

    /*根据优先级调整小堆的堆序*/
    while (node->parent && node->priority < node->parent->priority) {
        if (node == node->parent->left) {
            right_rotate(tree, node->parent);
        } else {
            left_rotate(tree, node->parent);
        }
    }
}

/* 二叉树查找函数 */
struct TreapNode* treap_find(struct Treap* tree, void* data)
{
    struct TreapNode* p = tree->root;
    while (p) {
        int r = tree->compare(data, p->data);
        if (r == 0) {
            return p;
        } else if (r < 0) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return NULL;
}

/**
 * 将被删除的节点旋转到少于2个子节点, 然后使用子节点代替
 */
struct TreapNode* Treap_remove(struct Treap* tree, void* data)
{
    struct TreapNode* node = treap_find(tree, data);
    if (node == NULL) {
        return NULL;
    }

    while (node->left && node->right) {
        if (node->left->priority < node->right->priority) {
            right_rotate(tree, node);
        } else {
            left_rotate(tree, node);
        }
    }

    struct TreapNode* tmp = NULL;
    if (node->left) {
        node->left->parent = node->parent;
        tmp = node->left;
    } else if (node->right) {
        node->right->parent = node->parent;
        tmp = node->right;
    }

    if (node->parent) {
        if (node == node->parent->left) {
            node->parent->left = tmp;
        } else if(node == node->parent->right){
            node->parent->right = tmp;
        } else {
            assert(0);
        }
    } else {
        tree->root = tmp;
    }
    return node;
}

/**
 * 中序遍历
 */
void Treap_inorder_walk(struct TreapNode* node,
    void (*callback)(struct TreapNode* node, void* userp), void* userp)
{
    if (!node)
        return;
    Treap_inorder_walk(node->left, callback, userp);
    callback(node, userp);
    Treap_inorder_walk(node->right, callback, userp);
}
