#ifndef UNION_FIND_H_INCLUDED
#define UNION_FIND_H_INCLUDED

#include <vector>

class UnionFind {
    std::vector<int> id_;
    int count_;

public:
    UnionFind(int n);
    void Union(int p, int q);
    int Find(int p) const;
    bool Connected(int p, int q) const { return Find(p) == Find(q); };
    int Count() const { return count_; };
};

#endif
