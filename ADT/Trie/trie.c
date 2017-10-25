#include "trie.h"
#include <stdlib.h>
#include <string.h>

Trie* trieCreate()
{
    Trie* obj = malloc(sizeof(Trie));
    if (!obj)
        return NULL;
    memset(&obj->root, 0, sizeof(TrieNode));
    return obj;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word)
{
    TrieNode* node = &obj->root;
    for (char* p = word; *p != '\0'; p++) {
        int index = INDEX(*p);
        if (!node->nexts[index]) {
            TrieNode* new_node = malloc(sizeof(TrieNode));
            memset(new_node, 0, sizeof(TrieNode));
            node->nexts[index] = new_node;
        }
        node = node->nexts[index];
    }
    node->count++;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word)
{
    TrieNode* node = &obj->root;
    for (char* p = word; *p != '\0'; p++) {
        int index = INDEX(*p);
        if (!node->nexts[index]) {
            return false;
        }
        node = node->nexts[index];
    }
    if (node->count > 0) {
        return true;
    } else {
        return false;
    }
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix)
{
    TrieNode* node = &obj->root;
    for (char* p = prefix; *p != '\0'; p++) {
        int index = INDEX(*p);
        if (!node->nexts[index]) {
            return false;
        }
        node = node->nexts[index];
    }
    return true;
}

void trieFreeNode(TrieNode* node)
{
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < TRIE_NEXTS_SIZE; i++) {
        trieFreeNode(node->nexts[i]);
    }
    free(node);
}

void trieFree(Trie* obj)
{
    TrieNode* node = &obj->root;
    for (int i = 0; i < TRIE_NEXTS_SIZE; i++) {
        trieFreeNode(node->nexts[i]);
    }
    free(obj);
}
