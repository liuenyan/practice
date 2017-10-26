#ifndef SCAPEGOAT_TREE_H_INCLUDED
#define SCAPEGOAT_TREE_H_INCLUDED

#include <stdbool.h>

#define SCAPEGOAT_ALPHA 0.667

struct scapegoat_node {
    void* data;
    int size;    //节点的数量
    struct scapegoat_node *parent, *left, *right;
};

struct scapegoat_tree {
    struct scapegoat_node* root;
    int (*compare)(void*, void*);
    void (*free_data)(void*);
    int size;
    int max_size;
};

struct scapegoat_tree* scapegoat_tree_new(int (*compare)(void*, void*),
    void (*free_data)(void*));
int scapegoat_tree_insert(struct scapegoat_tree* tree, void* data);
struct scapegoat_node* scapegoat_tree_find(struct scapegoat_tree* tree, void* data);
void scapegoat_tree_remove(struct scapegoat_tree* tree, void* data);
void scapegoat_tree_inorder_walk(struct scapegoat_node* node,
    void (*callback)(struct scapegoat_node* node, void* userp), void* userp);

#endif
