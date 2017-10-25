#include "SplayTree.h"
#include <stdlib.h>

struct SplayTree* SplayTree_new(int (*compare)(void*, void*), void (*free_data)(void*))
{
    struct SplayTree* tree = malloc(sizeof(*tree));
    if (!tree) {
        return NULL;
    }
    tree->root = NULL;
    tree->compare = compare;
    tree->free_data = free_data;
    return tree;
}

struct SplayTreeNode* SplayTree_new_node(void* data)
{
    struct SplayTreeNode* node = malloc(sizeof(*node));
    if (!node) {
        return NULL;
    }
    node->left = node->right = NULL;
    node->data = data;
    return node;
}

/**
 *     x           y
 *    / \         / \
 *   s   y   ->  x   z
 *      / \     / \
 *     w   z   s   w
 */
static inline struct SplayTreeNode* left_rotate(struct SplayTreeNode* x)
{
    struct SplayTreeNode* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

/*
 *     x           y
 *    / \         / \
 *   y   s   ->  w   x
 *  / \             / \
 * w   z           z   s
 */
static inline struct SplayTreeNode* right_rotate(struct SplayTreeNode* x)
{
    struct SplayTreeNode* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

static struct SplayTreeNode* splay(struct SplayTree* tree, struct SplayTreeNode* node, void* data)
{
    struct SplayTreeNode header;
    header.left = header.right = NULL;

    struct SplayTreeNode* left_tree_max = &header;
    struct SplayTreeNode* right_tree_min = &header;

    int r;
    while ((r = tree->compare(data, node->data)) != 0) {
        if (r < 0) {
            if (node->left == NULL) {
                break;
            }
            r = tree->compare(data, node->left->data);
            if (r < 0) {
                node = right_rotate(node);
                if (node->left == NULL) {
                    break;
                }
            }
            // link right
            right_tree_min->left = node;
            right_tree_min = node;
            node = node->left;
        } else {
            if (node->right == NULL) {
                break;
            }
            r = tree->compare(data, node->right->data);
            if (r > 0) {
                node = left_rotate(node);
                if (node->right == NULL) {
                    break;
                }
            }
            // link left;
            left_tree_max->right = node;
            left_tree_max = node;
            node = node->right;
        }
    }
    // reassemable
    left_tree_max->right = node->left;
    right_tree_min->left = node->right;
    node->left = header.right;
    node->right = header.left;

    return node;
}

int SplayTree_insert(struct SplayTree* tree, void* data)
{
    struct SplayTreeNode* new_node = NULL;
    if (tree->root == NULL) {
        new_node = SplayTree_new_node(data);
        if (!new_node) {
            return -1;
        }
        tree->root = new_node;
    } else {
        tree->root = splay(tree, tree->root, data);
        int r = tree->compare(data, tree->root->data);
        if (r == 0) {
            return 0;
        }
        new_node = SplayTree_new_node(data);
        if (!new_node) {
            return -1;
        }
        if (r < 0) {
            new_node->left = tree->root->left;
            new_node->right = tree->root;
            tree->root->left = NULL;
        } else {
            new_node->right = tree->root->right;
            new_node->left = tree->root;
            tree->root->right = NULL;
        }
        tree->root = new_node;
    }
    return 0;
}

int SplayTree_remove(struct SplayTree* tree, void* data)
{
    if (tree->root == NULL) {
        return -1;
    }
    tree->root = splay(tree, tree->root, data);
    int r = tree->compare(data, tree->root->data);
    if (r == 0) {
        struct SplayTreeNode* node = NULL;
        if (tree->root->left == NULL) {
            node = tree->root->right;
        } else {
            node = tree->root->left;
            node = splay(tree, node, data);
            node->right = tree->root->right;
        }
        if (tree->free_data) {
            tree->free_data(tree->root->data);
        }
        free(tree->root);
        tree->root = node;
        return 0;
    } else {
        return -1;
    }
}

struct SplayTreeNode* SplayTree_find(struct SplayTree* tree, void* data)
{
    if (tree->root == NULL) {
        return NULL;
    }
    tree->root = splay(tree, tree->root, data);
    int r = tree->compare(data, tree->root->data);
    if (r == 0) {
        return tree->root;
    } else {
        return NULL;
    }
}

/**
 * 中序遍历
 */
void SplayTree_inorder_walk(struct SplayTreeNode* node,
    void (*callback)(struct SplayTreeNode* node, void* userp), void* userp)
{
    if (node == NULL) {
        return;
    }
    SplayTree_inorder_walk(node->left, callback, userp);
    callback(node, userp);
    SplayTree_inorder_walk(node->right, callback, userp);
}
