#ifndef SPLAYTREE_H_INCLUDED
#define SPLAYTREE_H_INCLUDED

struct SplayTreeNode {
    void *data;
    struct SplayTreeNode *parent, *left, *right;
};

struct SplayTree {
    struct SplayTreeNode *root;
    int (*compare)(void *, void *);
};

struct SplayTreeNode* SplayTreeNode_new(void* data);
struct SplayTree *SplayTree_new(int (*compare)(void*, void*));
void SplayTree_insert(struct SplayTree* tree, struct SplayTreeNode* node);
struct SplayTreeNode *SplayTree_find(struct SplayTree* tree, void* data);
struct SplayTreeNode* SplayTree_remove(struct SplayTree* tree, void* data);
void SplayTree_inorder_walk(struct SplayTreeNode* node,
    void (*callback)(struct SplayTreeNode* node, void* userp), void* userp);
#endif
