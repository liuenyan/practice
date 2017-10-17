#include "treap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SZ 8

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

void print_node(struct TreapNode* node, void* userp)
{
    (void)userp;
    printf("%d %d\n", *(int*)node->data, node->priority);
}

int main(void)
{
    int arr[SZ];
    srand(time(NULL));
    for (int i = 0; i < SZ; i++) {
        arr[i] = rand() % 128;
        printf("%d\n", arr[i]);
    }
    printf("--------\n");

    struct Treap* tree = Treap_new(compare);
    assert(tree);

    for (int i = 0; i < SZ; i++) {
        struct TreapNode* node = TreapNode_new(tree, &arr[i]);
        assert(node);
        Treap_insert(tree, node);
    }
    Treap_inorder_walk(tree->root, print_node, NULL);

    for (int i = 0; i < SZ; i++) {
        //printf("--------remove: %d\n", arr[i]);
        struct TreapNode *n = Treap_remove(tree, &arr[i]);
        //Treap_inorder_walk(tree->root, print_node, NULL);
        assert(n);
        free(n);
    }
    return 0;
}
