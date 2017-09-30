#include "bst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define IN_LEFT(node) ((node) == (node)->parent->left)
#define IN_RIGHT(node) ((node) == (node)->parent->right)

/**
 * 先序遍历
 */
void BST_preorder_walk(struct TreeNode* node,
    void (*callback)(struct TreeNode* node, void* userp), void* userp)
{
    if (!node)
        return;
    callback(node, userp);
    BST_preorder_walk(node->left, callback, userp);
    BST_preorder_walk(node->right, callback, userp);
}

/**
 * 中序遍历
 */
void BST_inorder_walk(struct TreeNode* node,
    void (*callback)(struct TreeNode* node, void* userp), void* userp)
{
    if (!node)
        return;
    BST_inorder_walk(node->left, callback, userp);
    callback(node, userp);
    BST_inorder_walk(node->right, callback, userp);
}

/**
 * 后序遍历
 */
void BST_postorder_walk(struct TreeNode* node,
    void (*callback)(struct TreeNode* node, void* userp), void* userp)
{
    if (!node)
        return;
    BST_postorder_walk(node->left, callback, userp);
    BST_postorder_walk(node->right, callback, userp);
    callback(node, userp);
}

/**
 * 查找从当前节点开始最小值
 */
struct TreeNode* BST_minium(struct TreeNode* node)
{
    if (node == NULL) {
        return NULL;
    }

    struct TreeNode* p = node;
    while (p->left) {
        p = p->left;
    }
    return p;
}

/*查找从当前节点开始最大值*/
struct TreeNode* BST_maxium(struct TreeNode* node)
{
    if (node == NULL) {
        return NULL;
    }

    struct TreeNode* p = node;
    while (p->right) {
        p = p->right;
    }
    return p;
}

struct TreeNode* BST_successor(struct TreeNode* node)
{
    if (node->right) {
        return BST_maxium(node->right);
    }

    struct TreeNode* parent = node->parent;
    while (parent && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

/**
 * 二叉搜索树节点搜索函数
 */
struct TreeNode* BST_search(struct BST* tree, struct TreeNode* key_node)
{
    struct TreeNode* p = tree->root;
    while (p) {
        int r = tree->cmp(key_node->key, p->key);
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
 * 二叉查找树插入函数
 */
void BST_insert(struct BST* tree, struct TreeNode* node)
{
    struct TreeNode* p = tree->root;
    struct TreeNode* parent = NULL;
    while (p) {
        parent = p;
        int r = tree->cmp(node->key, p->key);
        if (r < 0) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    if (parent == NULL) {
        tree->root = node;
    } else {
        int r = tree->cmp(node->key, parent->key);
        if (r < 0) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }
    node->parent = parent;
}

static void BST_transplant(
    struct BST* tree, struct TreeNode* node, struct TreeNode* trans_node)
{
    // 节点为根结点
    if (node->parent == NULL) {
        tree->root = trans_node;
    } else if (IN_LEFT(node)) {
        // 节点位于左子树
        node->parent->left = trans_node;
    } else {
        // 节点位于右子树
        node->parent->right = trans_node;
    }

    if (trans_node != NULL) {
        trans_node->parent = node->parent;
    }
}

/**
 * 二叉搜索树节点删除函数
 */
struct TreeNode* BST_remove(struct BST* tree, struct TreeNode* del_node)
{
    if (del_node->left == NULL) {
        BST_transplant(tree, del_node, del_node->right);
    } else if (del_node->right == NULL) {
        BST_transplant(tree, del_node, del_node->left);
    } else {
        struct TreeNode* min_node = BST_minium(del_node->right);
        assert(min_node);
        if (min_node->parent != del_node) {
            BST_transplant(tree, min_node, min_node->right);
            min_node->right = del_node->right;
            min_node->right->parent = min_node;
        }
        BST_transplant(tree, del_node, min_node);
        min_node->left = del_node->left;
        min_node->parent = min_node;
    }
    return del_node;
}

