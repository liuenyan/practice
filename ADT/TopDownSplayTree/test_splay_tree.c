#include "SplayTree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SZ 32

int compare(void* x, void* y)
{
    if (*(int*)x == *(int*)y) {
        return 0;
    } else if (*(int*)x < *(int*)y) {
        return -1;
    } else {
        return 1;
    }
}

void print_node(struct SplayTreeNode* node, void* userp)
{
    (void)userp;
    printf("%d\n", *(int*)node->data);
}

int main(void)
{
    int arr[SZ];
    srand(time(NULL));
    for (int i = 0; i < SZ; i++) {
        arr[i] = rand() % 2309;
        printf("%d\n", arr[i]);
    }
    printf("--------\n");

    struct SplayTree* tree = SplayTree_new(compare, NULL);
    assert(tree);

    for (int i = 0; i < SZ; i++) {
        SplayTree_insert(tree, &arr[i]);
    }
    SplayTree_inorder_walk(tree->root, print_node, NULL);
    for (int i = 0; i < SZ; i++) {
        struct SplayTreeNode* n = SplayTree_find(tree, &arr[i]);
        if (n) {
            assert(n == tree->root);
        }
        printf("--------remove: %d\n", arr[i]);
        SplayTree_remove(tree, &arr[i]);
        SplayTree_inorder_walk(tree->root, print_node, NULL);
    }
    return 0;
}
