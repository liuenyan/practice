#include "SplayTree.h"
#include <assert.h>
#include <stdlib.h>

struct SplayTreeNode* find_min(struct SplayTreeNode* node)
{
    if (!node) {
        return NULL;
    }

    while (node->left) {
        node = node->left;
    }
    return node;
}

struct SplayTreeNode* find_max(struct SplayTreeNode* node)
{
    if (!node) {
        return NULL;
    }

    while (node->right) {
        node = node->right;
    }
    return node;
}

/**
 *     x           y
 *    / \         / \
 *   s   y   ->  x   z
 *      / \     / \
 *     w   z   s   w
 */
static void left_rotate(struct SplayTree* tree, struct SplayTreeNode* x)
{
    struct SplayTreeNode* y = x->right;
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
static void right_rotate(struct SplayTree* tree, struct SplayTreeNode* x)
{
    struct SplayTreeNode* y = x->left;
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

static void splay(struct SplayTree* tree, struct SplayTreeNode* node)
{
    assert(node);
    while (node->parent) {
        if (!node->parent->parent) {
            //zig
            if (node == node->parent->left) {
                right_rotate(tree, node->parent);
            } else {
                left_rotate(tree, node->parent);
            }
        } else if (node->parent == node->parent->parent->left) {
            if (node == node->parent->left) {
                // zig zig
                right_rotate(tree, node->parent->parent);
                right_rotate(tree, node->parent);
            } else {
                // zig zag
                left_rotate(tree, node->parent);
                right_rotate(tree, node->parent);
            }
        } else {
            if (node == node->parent->right) {
                // zig zig
                left_rotate(tree, node->parent->parent);
                left_rotate(tree, node->parent);
            } else {
                // zig zag
                right_rotate(tree, node->parent);
                left_rotate(tree, node->parent);
            }
        }
    }
}

struct SplayTreeNode* SplayTreeNode_new(void* data)
{
    struct SplayTreeNode* node = malloc(sizeof(struct SplayTreeNode));
    if (!node)
        return NULL;
    node->parent = node->left = node->right = NULL;
    node->data = data;
    return node;
}

struct SplayTree *SplayTree_new(int (*compare)(void*, void*))
{
    struct SplayTree* tree = malloc(sizeof(struct SplayTree));
    if (!tree)
        return NULL;
    tree->root = NULL;
    tree->compare = compare;
    return tree;
}

void SplayTree_insert(struct SplayTree* tree, struct SplayTreeNode* node)
{
    struct SplayTreeNode* p = tree->root;
    struct SplayTreeNode* prev = NULL;

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
    splay(tree, node);
}

struct SplayTreeNode *SplayTree_find(struct SplayTree* tree, void* data)
{
    struct SplayTreeNode *node = NULL;
    for (struct SplayTreeNode* p = tree->root; p;) {
        int r = tree->compare(data, p->data);
        if (r == 0) {
            node = p;
            break;
        } else if (r < 0) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    if (node) {
        splay(tree, node);
    }
    return node;
}

static void transplant(struct SplayTree* tree, struct SplayTreeNode* u, struct SplayTreeNode* v)
{
    if (!u->parent) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v) {
        v->parent = u->parent;
    }
}

struct SplayTreeNode* SplayTree_remove(struct SplayTree* tree, void* data)
{
    struct SplayTreeNode* node = SplayTree_find(tree, data);
    if (!node) {
        return NULL;
    }

    if (!node->left) {
        transplant(tree, node, node->right);
    } else if (!node->right) {
        transplant(tree, node, node->left);
    } else {
        struct SplayTreeNode* y = find_min(node->right);
        if (y->parent != node) {
            transplant(tree, y, y->right);
            y->right = node->right;
            node->right->parent = y;
        }
        transplant(tree, node, y);
        y->left = node->left;
        node->left->parent = y;
    }
    return node;
}

/**
 * 中序遍历
 */
void SplayTree_inorder_walk(struct SplayTreeNode* node,
    void (*callback)(struct SplayTreeNode* node, void* userp), void* userp)
{
    if (!node)
        return;
    SplayTree_inorder_walk(node->left, callback, userp);
    callback(node, userp);
    SplayTree_inorder_walk(node->right, callback, userp);
}
