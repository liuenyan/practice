#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <stdbool.h>

#define TRIE_NEXTS_SIZE 26
#define INDEX(ch) ((ch) - 'a')

typedef struct TrieNode {
    int count;
    struct TrieNode* nexts[TRIE_NEXTS_SIZE];
} TrieNode;

typedef struct Trie {
    TrieNode root;
} Trie;

Trie* trieCreate();
void trieInsert(Trie* obj, char* word);
bool trieSearch(Trie* obj, char* word);
bool trieStartsWith(Trie* obj, char* prefix);
void trieFree(Trie* obj);

#endif
