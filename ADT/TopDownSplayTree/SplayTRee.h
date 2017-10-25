#ifndef TOPDOWN_SPLAYTREE_H_INCLUDED
#define TOPDOWN_SPLAYTREE_H_INCLUDED

struct SplayTreeNode {
    void* data;
    struct SplayTreeNode *left, *right;
};

struct SplayTree {
    struct SplayTreeNode* root;
    int (*compare)(void*, void*);
    void (*free_data)(void*);
};

struct SplayTree* SplayTree_new(int (*compare)(void*, void*), void (*free_data)(void*));
struct SplayTreeNode* SplayTree_new_node(struct SplayTree* tree, void* data);
int SplayTree_insert(struct SplayTree* tree, void* data);
int SplayTree_remove(struct SplayTree* tree, void* data);
struct SplayTreeNode* SplayTree_find(struct SplayTree* tree, void* data);
void SplayTree_inorder_walk(struct SplayTreeNode* node,
    void (*callback)(struct SplayTreeNode* node, void* userp), void* userp);

#endif
