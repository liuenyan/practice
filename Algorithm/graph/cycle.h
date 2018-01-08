#ifndef CYCLE_H_INCLUED
#define CYCLE_H_INCLUED

#include "graph.h"
#include <vector>

class Cycle {
    std::vector<int> marked_;
    bool has_cycle_;

    void dfs(const Graph &g, int v, int u);
public:
    Cycle(const Graph &g);
    bool HasCycle() const { return has_cycle_; };
};

#endif
