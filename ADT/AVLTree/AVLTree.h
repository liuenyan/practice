#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED 1

struct AVLTreeNode {
    void* data;
    int height;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
};

struct AVLTree {
    struct AVLTreeNode* root;
    int (*compare)(struct AVLTreeNode* p1, struct AVLTreeNode* p2);
};

struct AVLTreeNode* AVLTreeNode_new(void* data);
struct AVLTree* AVLTree_new(
    int (*compare)(struct AVLTreeNode* p1, struct AVLTreeNode* p2));
void AVLTree_insert(struct AVLTree* tree, struct AVLTreeNode* node);

struct AVLTreeNode* AVLTree_find(
    struct AVLTree* tree, struct AVLTreeNode* node);

struct AVLTreeNode* AVLTree_min(struct AVLTreeNode *node);

void AVLTree_inorder_walk(struct AVLTreeNode* node,
    void (*callback)(struct AVLTreeNode*, void*), void* userp);

#endif /* ifndef AVLTREE_H_INCLUDED */
