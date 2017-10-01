#include "AVLTree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct AVLTree* AVLTree_new(
    int (*compare)(struct AVLTreeNode* p1, struct AVLTreeNode* p2))
{
    struct AVLTree* tree = malloc(sizeof(*tree));
    if (!tree)
        return NULL;

    tree->root = NULL;
    tree->compare = compare;
    return tree;
}

struct AVLTreeNode* AVLTreeNode_new(void* data)
{
    struct AVLTreeNode* node = malloc(sizeof(*node));
    if (!node)
        return NULL;
    node->data = data;
    node->height = 0;
    node->left = node->right = NULL;
    return node;
}

static inline int AVLTreeNode_height(struct AVLTreeNode* p)
{
    return (p) ? (p->height) : -1;
}

static inline int max_int(int x, int y) { return x > y ? x : y; }

static struct AVLTreeNode* LL_rotate(struct AVLTreeNode* p)
{
    printf("LL\n");
    struct AVLTreeNode* q = p->left;
    p->left = q->right;
    q->right = p;

    p->height
        = max_int(AVLTreeNode_height(p->left), AVLTreeNode_height(p->right))
        + 1;
    q->height = max_int(AVLTreeNode_height(q->left), p->height);
    return q;
}

static struct AVLTreeNode* RR_rotate(struct AVLTreeNode* p)
{
    printf("RR\n");
    struct AVLTreeNode* q = p->right;
    p->right = q->left;
    q->left = p;

    p->height
        = max_int(AVLTreeNode_height(p->left), AVLTreeNode_height(p->right))
        + 1;
    q->height = max_int(AVLTreeNode_height(q->right), p->height);
    return q;
}

static struct AVLTreeNode* LR_rotate(struct AVLTreeNode* p)
{
    printf("LR\n");
    p->left = RR_rotate(p->left);
    return LL_rotate(p);
}

static struct AVLTreeNode* RL_rotate(struct AVLTreeNode* p)
{

    printf("RL\n");
    p->right = LL_rotate(p->right);
    return RR_rotate(p);
}

static struct AVLTreeNode* insert(
    struct AVLTree* tree, struct AVLTreeNode* p, struct AVLTreeNode* q)
{
    if (p == NULL) {
        return q;
    }

    int r = tree->compare(q, p);
    if (r < 0) {
        p->left = insert(tree, p->left, q);
        if (AVLTreeNode_height(p->left) - AVLTreeNode_height(p->right) == 2) {
            int r = tree->compare(q, p->left);
            if (r < 0) {
                p = LL_rotate(p);
            } else {
                p = LR_rotate(p);
            }
        }
    } else {
        p->right = insert(tree, p->right, q);
        if (AVLTreeNode_height(p->right) - AVLTreeNode_height(p->left) == 2) {
            int r = tree->compare(q, p->right);
            if (r < 0) {
                p = RL_rotate(p);
            } else {
                p = RR_rotate(p);
            }
        }
    }
    p->height
        = max_int(AVLTreeNode_height(p->left), AVLTreeNode_height(p->right))
        + 1;
    return p;
}

void AVLTree_insert(struct AVLTree* tree, struct AVLTreeNode* node)
{
    tree->root = insert(tree, tree->root, node);
}

struct AVLTreeNode* AVLTree_find(
    struct AVLTree* tree, struct AVLTreeNode* node)
{
    struct AVLTreeNode* p = tree->root;
    while (p) {
        int r = tree->compare(node, p);
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

struct AVLTreeNode* AVLTree_min(struct AVLTreeNode* node)
{
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

void AVLTree_inorder_walk(struct AVLTreeNode* node,
    void (*callback)(struct AVLTreeNode*, void*), void* userp)
{
    if (!node) {
        return;
    }

    AVLTree_inorder_walk(node->left, callback, userp);
    callback(node, userp);
    AVLTree_inorder_walk(node->right, callback, userp);
}
