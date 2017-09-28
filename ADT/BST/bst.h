#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

struct TreeNode {
    void* key;
    struct TreeNode* parent;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct BST {
    //根结点
    struct TreeNode* root;
    //关键字比较函数
    int (*cmp)(void*, void*);
};

#define BST_init(tree, cmp_func)                                             \
    do {                                                                     \
        (tree)->root = NULL;                                                 \
        (tree)->cmp = cmp_func;                                              \
    } while (0)

#define TreeNode_init(node)                                                  \
    do {                                                                     \
        (node)->parent = NULL;                                               \
        (node)->left = NULL;                                                 \
        (node)->right = NULL;                                                \
    } while (0)

void BST_preorder_walk(struct TreeNode* node,
    void (*callback)(struct TreeNode* node, void* userp), void* userp);

void BST_inorder_walk(struct TreeNode* node,
    void (*callback)(struct TreeNode* node, void* userp), void* userp);

void BST_postorder_walk(struct TreeNode* node,
    void (*callback)(struct TreeNode* node, void* userp), void* userp);

struct TreeNode* BST_minium(struct TreeNode* node);

struct TreeNode* BST_maxium(struct TreeNode* node);

struct TreeNode* BST_successor(struct TreeNode* node);

struct TreeNode* BST_search(struct BST* tree, struct TreeNode* key_node);

void BST_insert(struct BST* tree, struct TreeNode* node);

struct TreeNode* BST_remove(struct BST* tree, struct TreeNode* del_node);

#endif
