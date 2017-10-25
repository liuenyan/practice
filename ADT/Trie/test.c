#include "trie.h"
#include <stdio.h>

int main(void)
{
    Trie* obj = trieCreate();
    trieInsert(obj, "apple");
    trieInsert(obj, "append");
    bool param_2 = trieSearch(obj, "apple");
    bool param_3 = trieStartsWith(obj, "app");
    printf("%d %d\n", param_2, param_3);
    trieFree(obj);
}
