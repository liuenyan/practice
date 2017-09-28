#include "bst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(void* p1, void* p2) { return strcmp((char*)p1, (char*)p2); }

void callback(struct TreeNode* node, void* userp)
{
    (void)userp;
    printf("%s\n", (char*)node->key);
}

int main(void)
{
    char* data[] = {
        "d",
        "b",
        "c",
        "f",
        "a",
        "g",
        "e",
    };

    int sz = (int)(sizeof(data) / sizeof(char*));

    struct BST tree;

    BST_init(&tree, compare);

    for (int i = 0; i < sz; i++) {
        struct TreeNode* node = malloc(sizeof(*node));
        TreeNode_init(node);
        node->key = data[i];
        BST_insert(&tree, node);
    }
    BST_inorder_walk(tree.root, callback, NULL);
    printf("----\n");
    BST_preorder_walk(tree.root, callback, NULL);
    printf("----\n");
    BST_postorder_walk(tree.root, callback, NULL);
    printf("----\n");

    struct TreeNode key_node;
    TreeNode_init(&key_node);
    key_node.key = "a";

    struct TreeNode* min_node = BST_minium(tree.root);
    printf("%s\n", (char*)min_node->key);

    struct TreeNode* max_node = BST_maxium(tree.root);
    printf("%s\n", (char*)max_node->key);
    printf("----\n");

    struct TreeNode* find = BST_search(&tree, &key_node);
    assert(find);
    assert(strcmp(find->key, key_node.key) == 0);

    BST_remove(&tree, find);
    BST_inorder_walk(tree.root, callback, NULL);
    free(find);

    return 0;
}
