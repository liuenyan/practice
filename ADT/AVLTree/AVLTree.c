#include "AVLTree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// 创建新的AVL树
struct AVLTree* AVLTree_new(
    int (*compare)(void* key1, void* key2),
    void (*free_key)(void* key),
    void (*free_value)(void* value))
{
    struct AVLTree* tree = malloc(sizeof(*tree));
    if (!tree)
        return NULL;

    tree->root = NULL;
    tree->compare = compare;
    tree->free_key = free_key;
    tree->free_value = free_value;
    return tree;
}

// 创建新节点
static struct AVLTreeNode* AVLTreeNode_new(void* key, void* value)
{
    struct AVLTreeNode* node = malloc(sizeof(*node));
    if (!node)
        return NULL;
    node->key = key;
    node->value = value;
    node->height = 0;
    node->left = node->right = NULL;
    return node;
}

// 计算树的高度
static inline int height(struct AVLTreeNode* p)
{
    return (p) ? (p->height) : -1;
}

static inline int max_integer(int x, int y)
{
    return x > y ? x : y;
}

// 更新节点的高度信息
static inline int update_height(struct AVLTreeNode* node)
{
    return max_integer(height(node->left), height(node->right)) + 1;
}

// 计算平衡因子
static inline int factor(struct AVLTreeNode* node)
{
    return height(node->left) - height(node->right);
}

// 左旋操作
static struct AVLTreeNode* rotate_left(struct AVLTreeNode* x)
{
    struct AVLTreeNode* y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = update_height(x);
    y->height = update_height(y);
    return y;
}

// 右旋操作
static struct AVLTreeNode* rotate_right(struct AVLTreeNode* x)
{
    struct AVLTreeNode* y = x->left;
    x->left = y->right;
    y->right = x;

    x->height = update_height(x);
    y->height = update_height(y);
    return y;
}

// 重新平衡二叉树
static struct AVLTreeNode* balance(
    struct AVLTree* tree, struct AVLTreeNode* root, void* key)
{
    int f1 = factor(root);
    if (f1 > 1) {
        // left heavy
        if (factor(root->left) < 0) {
            // left right
            root->left = rotate_left(root->left);
        }
        // left left
        root = rotate_right(root);
    } else if (f1 < -1) {
        // right heavy
        if (factor(root->right) > 0) {
            // right left
            root->right = rotate_right(root->right);
        }
        // right right
        root = rotate_left(root);
    }
    return root;
}

static struct AVLTreeNode* insert(
    struct AVLTree* tree, struct AVLTreeNode* root, void* key, void* value)
{
    if (root == NULL) {
        struct AVLTreeNode* node = AVLTreeNode_new(key, value);
        assert(node);
        return node;
    }

    int cmp = tree->compare(key, root->key);
    if (cmp == 0) {
        // 键相等, 替换旧值
        void* old_value = root->value;
        root->value = value;
        if (tree->free_value != NULL) {
            tree->free_value(old_value);
        }
        return root;
    } else if (cmp < 0) {
        root->left = insert(tree, root->left, key, value);
    } else {
        root->right = insert(tree, root->right, key, value);
    }
    root->height = update_height(root);
    return balance(tree, root, key);
}

void AVLTree_insert(struct AVLTree* tree, void* key, void* value)
{
    tree->root = insert(tree, tree->root, key, value);
}

/**
 * 查找键对应的值。成功返回0, 失败返回-1，如果成功将对应的值输出到value中
 */
int AVLTree_find(struct AVLTree* tree, void* key, void** value)
{
    struct AVLTreeNode* p = tree->root;
    while (p) {
        int cmp = tree->compare(key, p->key);
        if (cmp == 0) {
            *value = p->value;
            return 0;
        } else if (cmp < 0) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return -1;
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
