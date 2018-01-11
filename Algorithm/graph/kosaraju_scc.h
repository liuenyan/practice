#ifndef KOSARAJU_SCC_H_INCLUED
#define KOSARAJU_SCC_H_INCLUED

#include "digraph.h"

class KosarajuSCC {
    int count_;
    std::vector<int> marked_;
    std::vector<int> id_;

    void dfs(const Digraph& g, int v);

public:
    explicit KosarajuSCC(const Digraph& g);
    bool StronglyConnected(int v, int w) const { return id_[v] == id_[w]; };
    int Count() const { return count_; };
    int Id(int v) const { return id_[v]; };
};

#endif
