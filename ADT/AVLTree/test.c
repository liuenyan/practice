#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "AVLTree.h"

int compare(struct AVLTreeNode *p1, struct AVLTreeNode *p2)
{
    return strcmp(p1->data, p2->data);
}

void print(struct AVLTreeNode *node, void *userp)
{
    (void)userp;
    printf("%s %d\n", (char *)node->data, node->height);
}

int main()
{
    char *data[] = {
        "pear",
        "apple",
        "banana",
        "hello",
        "world",
        "python",
        "computer",
        "system",
        "less",
        "more",
        "eye",
        "shoulder",
        "tcp"
    };
    struct AVLTree *tree = AVLTree_new(compare);
    assert(tree);

    for(int i = 0; i < (int)(sizeof(data)/sizeof(char *)); i++) {
        struct AVLTreeNode *node = AVLTreeNode_new(data[i]);
        AVLTree_insert(tree, node);
    }
    AVLTree_inorder_walk(tree->root, print, NULL);
    return 0;
}
