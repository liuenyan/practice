#include "ScapegoatTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define SZ 63

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

void print_node(struct scapegoat_node* node, void* userp)
{
    (void)userp;
    printf("data: %d, size: %d\n", *(int*)node->data, node->size);
}

int main(void)
{
    struct scapegoat_tree *tree = scapegoat_tree_new(compare, NULL);
    assert(tree);
    //int arr[SZ] = {2, 1, 4, 3};
    //int arr[SZ] = {2, 1, 4, 5};
    int arr[SZ];

    srand(time(NULL));

    for(int i=0; i<SZ; i++) {
        arr[i] = rand() % 11003;
    }

    for(int i=0; i < SZ; i++) {
        scapegoat_tree_insert(tree, &arr[i]);
    }
    scapegoat_tree_inorder_walk(tree->root, print_node, NULL);
    for(int i=0; i < SZ; i++) {
        printf("remove %d\n", arr[i]);
        scapegoat_tree_remove(tree, &arr[i]);
    }
    return 0;
}
