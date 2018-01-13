#include "union_find.h"

UnionFind::UnionFind(int n)
    : count_(n)
{
    for (int i = 0; i < n; i++) {
        id_.push_back(i);
    }
}

void UnionFind::Union(int p, int q)
{
    int p_root = Find(p);
    int q_root = Find(q);

    if (p_root == q_root) {
        return;
    }

    id_[p_root] = q_root;
    count_--;
}

int UnionFind::Find(int p) const
{
    while (id_[p] != p) {
        p = id_[p];
    }
    return p;
}
