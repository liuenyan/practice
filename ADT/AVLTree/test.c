#include "AVLTree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(void* p1, void* p2)
{
    return strcmp(p1, p2);
}

void print(struct AVLTreeNode* node, void* userp)
{
    (void)userp;
    printf("%s %d\n", (char*)node->key, node->height);
}

int main()
{
    char* data[] = {
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
    struct AVLTree* tree = AVLTree_new(compare, NULL, NULL);
    assert(tree);

    for (int i = 0; i < (int)(sizeof(data) / sizeof(char*)); i++) {
        AVLTree_insert(tree, data[i], NULL);
    }
    AVLTree_inorder_walk(tree->root, print, NULL);
    printf("----\n");
    for(int i = 0; i < (int)(sizeof(data)/sizeof(char*)); i++) {
        AVLTree_remove(tree, data[i]);
        AVLTree_inorder_walk(tree->root, print, NULL);
        printf("----\n");
    }
    return 0;
}
