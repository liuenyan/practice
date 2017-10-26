#include "ScapegoatTree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct scapegoat_tree* scapegoat_tree_new(int (*compare)(void*, void*),
    void (*free_data)(void*))
{
    struct scapegoat_tree* tree = malloc(sizeof(*tree));
    if (tree) {
        tree->root = NULL;
        tree->compare = compare;
        tree->free_data = free_data;
        tree->size = tree->max_size = 0;
    }
    return tree;
}

static struct scapegoat_node* scapegoat_node_new(void* data)
{
    struct scapegoat_node* node = malloc(sizeof(*node));
    if (node) {
        node->parent = node->left = node->right = NULL;
        node->size = 1;
        node->data = data;
    }
    return node;
}
//收集所有重构的节点信息
static void travel(struct scapegoat_tree* tree, struct scapegoat_node* node,
    struct scapegoat_node* all_nodes[], int* count)
{
    if (node == NULL) {
        return;
    }
    travel(tree, node->left, all_nodes, count);
    all_nodes[*count] = node;
    (*count) += 1;
    travel(tree, node->right, all_nodes, count);
}

static struct scapegoat_node* build(struct scapegoat_node* all_nodes[], int begin, int end)
{
    if (begin > end) {
        return NULL;
    }
    int middle = (begin + end + 1) / 2;
    struct scapegoat_node* p = all_nodes[middle];
    p->size = end - begin + 1;
    p->left = build(all_nodes, begin, middle - 1);
    if (p->left != NULL) {
        p->left->parent = p;
    }
    p->right = build(all_nodes, middle + 1, end);
    if (p->right != NULL) {
        p->right->parent = p;
    }
    return p;
}

static void rebuild(struct scapegoat_tree* tree, struct scapegoat_node* node)
{
    if (node == NULL) {
        return;
    }
    struct scapegoat_node** all_nodes = calloc(node->size, sizeof(*all_nodes));
    assert(all_nodes);
    int count = 0;
    travel(tree, node, all_nodes, &count);

    assert(count == node->size);

    struct scapegoat_node* parent = node->parent;
    struct scapegoat_node* subtree = build(all_nodes, 0, node->size - 1);
    if (parent == NULL) {
        tree->root = subtree;
        tree->root->parent = NULL;
    } else if (node == parent->left) {
        parent->left = subtree;
        parent->left->parent = parent;
    } else {
        parent->right = subtree;
        parent->right->parent = parent;
    }
    tree->max_size = tree->size;
}

int scapegoat_tree_insert(struct scapegoat_tree* tree, void* data)
{
    // 二叉树为空
    if (tree->root == NULL) {
        tree->root = scapegoat_node_new(data);
        if (tree->root == NULL) {
            return -1;
        } else {
            tree->size += 1;
            tree->max_size += 1;
            return 0;
        }
    }
    // 查找一个插入的位置
    struct scapegoat_node* previous = NULL;
    struct scapegoat_node* current = tree->root;
    int r = 0;
    while (current != NULL) {
        r = tree->compare(data, current->data);
        if (r == 0) {
            return 0;
        }
        previous = current;
        if (r < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // 插入新节点
    struct scapegoat_node* new_node = scapegoat_node_new(data);
    if (new_node == NULL) {
        return -1;
    }
    if (r < 0) {
        previous->left = new_node;
    } else {
        previous->right = new_node;
    }
    new_node->parent = previous;

    tree->size += 1;
    tree->max_size += 1;

    //回溯并更新size信息, 同时找到需要进行重构的节点
    struct scapegoat_node* scapegoat = NULL;
    for (struct scapegoat_node* p = new_node; p->parent != NULL; p = p->parent) {
        p->parent->size += 1;
        if (p->size >= p->parent->size * SCAPEGOAT_ALPHA) {
            scapegoat = p;
        }
    }
    //重建二叉树
    if (scapegoat != NULL) {
        rebuild(tree, scapegoat);
    }
    return 0;
}
/* 二叉树查找函数 */
struct scapegoat_node* scapegoat_tree_find(struct scapegoat_tree* tree, void* data)
{
    struct scapegoat_node* p = tree->root;
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

static void transplant(struct scapegoat_tree* tree, struct scapegoat_node* u, struct scapegoat_node* v)
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

static struct scapegoat_node* find_min(struct scapegoat_node* node)
{
    if (!node) {
        return NULL;
    }

    while (node->left) {
        node = node->left;
    }
    return node;
}

void scapegoat_tree_remove(struct scapegoat_tree* tree, void* data)
{
    struct scapegoat_node* node = scapegoat_tree_find(tree, data);
    if (!node) {
        return;
    }
    struct scapegoat_node* z = node->parent;
    if (!node->left) {
        transplant(tree, node, node->right);
    } else if (!node->right) {
        transplant(tree, node, node->left);
    } else {
        struct scapegoat_node* y = find_min(node->right);
        if (y->parent != node) {
            z = y->parent;
            transplant(tree, y, y->right);
            y->right = node->right;
            node->right->parent = y;
            for (; z != y; z = z->parent) {
                z->size -= 1;
            }
            z = node->parent;
        }
        transplant(tree, node, y);
        y->left = node->left;
        node->left->parent = y;
        y->size = node->size - 1;
    }
    if (z != NULL) {
        for (; z; z = z->parent) {
            z->size -= 1;
        }
    }

    //释放被删除的节点
    if (tree->free_data) {
        tree->free_data(node->data);
    }
    free(node);
    tree->size -= 1;

    if (tree->size < tree->max_size * SCAPEGOAT_ALPHA) {
        rebuild(tree, tree->root);
    }
}

/**
 * 中序遍历
 */
void scapegoat_tree_inorder_walk(struct scapegoat_node* node,
    void (*callback)(struct scapegoat_node* node, void* userp), void* userp)
{
    if (node == NULL) {
        return;
    }
    scapegoat_tree_inorder_walk(node->left, callback, userp);
    callback(node, userp);
    scapegoat_tree_inorder_walk(node->right, callback, userp);
}
