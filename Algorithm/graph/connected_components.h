#ifndef CONNECTED_COMPONENTS_H_INCLUED
#define CONNECTED_COMPONENTS_H_INCLUED

#include "graph.h"
#include <vector>

class ConnectedComponents {
    std::vector<int> marked_;
    std::vector<int> id_;
    int count_;

    void dfs(const Graph &g, int v);
public:
    ConnectedComponents(const Graph &g);
    bool Connected(int v, int w) const { return id_[v] == id_[w]; };
    int Id(int v) const { return id_[v]; };
    int Count() const { return count_; };
};

#endif
