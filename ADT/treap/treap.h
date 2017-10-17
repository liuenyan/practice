#ifndef TREAP_H_INCLUDED
#define TREAP_H_INCLUDED 1

struct TreapNode {
    void *data;
    int priority;
    struct TreapNode *parent, *left, *right;
};

struct Treap {
    struct TreapNode *root;
    int (*compare)(void *data1, void *data2);
    unsigned int seed;
};

struct Treap* Treap_new(int (*compare)(void*, void*));
struct TreapNode* TreapNode_new(struct Treap* tree, void* data);
void Treap_insert(struct Treap* tree, struct TreapNode* node);
struct TreapNode* Treap_find(struct Treap* tree, void* data);
struct TreapNode* Treap_remove(struct Treap* tree, void* data);
void Treap_inorder_walk(struct TreapNode* node,
    void (*callback)(struct TreapNode* node, void* userp), void* userp);

#endif /* ifndef TREAP_H_INCLUDED */
