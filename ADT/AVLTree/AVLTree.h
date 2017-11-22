#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

struct AVLTreeNode {
    void* key;
    void* value;
    int height;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
};

struct AVLTree {
    struct AVLTreeNode* root;
    int (*compare)(void* key1, void* key2);
    void (*free_key)(void* key);
    void (*free_value)(void* value);
};

struct AVLTree* AVLTree_new(
    int (*compare)(void* key1, void* key2),
    void (*free_key)(void* key),
    void (*free_value)(void* value));

void AVLTree_insert(struct AVLTree* tree, void* key, void* value);
int AVLTree_remove(struct AVLTree* tree, void* key);

int AVLTree_find(struct AVLTree* tree, void* key, void** value);

void AVLTree_inorder_walk(struct AVLTreeNode* node,
    void (*callback)(struct AVLTreeNode*, void*), void* userp);

#endif /* ifndef AVLTREE_H_INCLUDED */
